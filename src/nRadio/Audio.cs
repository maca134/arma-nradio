using System;
using System.Collections.Generic;
using System.IO;
using System.Threading;
using System.Threading.Tasks;
using NAudio.Wave;

namespace nRadio
{
    public delegate IWaveProvider WaveProviderCreated(IWaveProvider provider);

    public class Audio
    {
        public event WaveProviderCreated onWaveProviderCreated;

        bool IsPlaying
        {
            get;
            set;
        }
        Task playTask;

        public Audio()
        {
            stream = new SlidingStream();
        }

        public void OnCurrentSongChanged(object sender, CurrentSongEventArgs args)
        {}

        public void OnStreamUpdate(object sender, StreamUpdateEventArgs args)
        {
            stream.Write(args.Data, 0, args.Data.Length);
            if (!IsPlaying)
                StartPlay();
        }

        void StartPlay()
        {
            IsPlaying = true;
            playTask = Task.Factory.StartNew(DecompressFrames);
        }

        #region NAudio

        readonly SlidingStream stream;

        private void DecompressFrames()
        {
            IMp3FrameDecompressor decompressor = null;
            IWavePlayer waveOut = null;
            try
            {
                BufferedWaveProvider bufferedWaveProvider = null;
                var buffer = new byte[16384 * 4]; // needs to be big enough to hold a decompressed frame
                var firstLoop = true;

                do
                {
                    //WaveBuffer getting full, taking a break
                    if (bufferedWaveProvider != null && bufferedWaveProvider.BufferLength - bufferedWaveProvider.BufferedBytes < bufferedWaveProvider.WaveFormat.AverageBytesPerSecond / 4)
                    {
                        Thread.Sleep(500);
                    }
                    //StreamBuffer empty, taking a break
                    else if (stream.Length < 16384 * 2)
                    {
                        Thread.Sleep(500);
                    }
                    else
                    {
                        Mp3Frame frame;
                        try
                        {
                            frame = Mp3Frame.LoadFromStream(stream);
                        }
                        catch (EndOfStreamException)
                        {
                            break;
                        }
                        if (frame == null)
                            continue;
                        if (decompressor == null)
                        {
                            WaveFormat waveFormat = new Mp3WaveFormat(frame.SampleRate, frame.ChannelMode == ChannelMode.Mono ? 1 : 2, frame.FrameLength, frame.BitRate);
                            decompressor = new AcmMp3FrameDecompressor(waveFormat);
                            bufferedWaveProvider = new BufferedWaveProvider(decompressor.OutputFormat)
                            {
                                BufferDuration = TimeSpan.FromSeconds(5)
                            };
                            // allow us to get well ahead of ourselves
                        }
                        var decompressed = decompressor.DecompressFrame(frame, buffer, 0);
                        if (decompressed > 0)
                            bufferedWaveProvider.AddSamples(buffer, 0, decompressed);

                        if (firstLoop)
                        {
                            firstLoop = false;
                            waveOut = CreateWaveOut();
                            if (onWaveProviderCreated != null)
                            {
                                var provider = onWaveProviderCreated(bufferedWaveProvider);
                                waveOut.Init(provider);
                            }
                            waveOut.Play();
                        }
                    }

                } while (IsPlaying);
            }
            finally
            {
                if (waveOut != null)
                {
                    waveOut.Stop();
                    waveOut.Dispose();
                }
                if (decompressor != null)
                {
                    decompressor.Dispose();
                }
            }
        }

        private IWavePlayer CreateWaveOut()
        {
            return new WaveOut();
        }
        #endregion

        public void Dispose()
        {
            IsPlaying = false;
            if(playTask != null)
                playTask.Wait();
            stream.Dispose();
        }
    }

    class SlidingStream : Stream
    {
        public override bool CanRead
        {
            get { throw new NotImplementedException(); }
        }

        public override bool CanSeek
        {
            get { throw new NotImplementedException(); }
        }

        public override bool CanWrite
        {
            get { throw new NotImplementedException(); }
        }

        public override void Flush()
        {
            throw new NotImplementedException();
        }

        public override long Length
        {
            get { return _length; }
        }
        int _length;

        public override long Position
        {
            get
            {
                return 0;
            }
            set
            {
                throw new NotImplementedException();
            }
        }

        readonly Queue<byte[]> blocks;
        byte[] currentBlock;

        public SlidingStream()
        {
            blocks = new Queue<byte[]>();
        }

        public override int Read(byte[] buffer, int offset, int count)
        {
            if (_length < count)
                count = _length;

            if (blocks.Count == 0)
                return 0;

            var readCount = 0;
            if (currentBlock == null || currentBlock.Length == 0)
                currentBlock = blocks.Dequeue();

            while (readCount < count)
            {
                if (readCount + currentBlock.Length < count)
                {
                    Buffer.BlockCopy(currentBlock, 0, buffer, offset + readCount, currentBlock.Length);
                    readCount += currentBlock.Length;
                    currentBlock = blocks.Dequeue();
                }
                else
                {
                    Buffer.BlockCopy(currentBlock, 0, buffer, offset + readCount, count - readCount);
                    //resize the queued buffer to store only the unread data
                    Buffer.BlockCopy(currentBlock, count - readCount, currentBlock, 0, currentBlock.Length - (count - readCount));
                    Array.Resize(ref currentBlock, currentBlock.Length - (count - readCount));
                    readCount = count;
                    break;
                }
            }

            _length -= readCount;

            return readCount;
        }

        public override long Seek(long offset, SeekOrigin origin)
        {
            throw new NotImplementedException();
        }

        public override void SetLength(long value)
        {
            throw new NotImplementedException();
        }

        public override void Write(byte[] buffer, int offset, int count)
        {
            var bufferCopy = new byte[count];
            Buffer.BlockCopy(buffer, offset, bufferCopy, 0, count);
            blocks.Enqueue(bufferCopy);
            _length += count;
        }
    }
}
