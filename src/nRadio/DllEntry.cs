using System;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using NAudio.Wave;
using RGiesecke.DllExport;

namespace nRadio
{
    public class DllEntry
    {
        public enum Status
        {
            STOP,
            WAITING,
            PLAYING
        }

        private static DllEntry _instance;

        [DllExport("_RVExtension@12", CallingConvention = CallingConvention.Winapi)]
        public static void RVExtension(StringBuilder output, int outputSize, string function)
        {
            if (_instance == null)
                _instance = new DllEntry();
            function = function.Replace(@"\n", "\n");
            output.Append(_instance.Invoke(function));
        }

        private Radio radio;
        private Audio audio;
        private float volume = 50;
        private VolumeWaveProvider16 volumeProvider;

        private Task fadingTask;
        private bool cancelFading;
        private Status status = Status.STOP;

        private bool isPlaying;

        private DllEntry()
        {
#if DEBUG
            ConsoleHelper.CreateConsole();
#endif
        }

        public string DecodeFromUtf8(string utf8String)
        {
            var utf8Bytes = new byte[utf8String.Length];
            for (var i = 0; i < utf8String.Length; ++i)
            {
                utf8Bytes[i] = (byte)utf8String[i];
            }

            return Encoding.UTF8.GetString(utf8Bytes, 0, utf8Bytes.Length);
        }

        private string Invoke(string function)
        {
            var lines = function.Split('\n');
            var cmd = lines[0];
            string data;
            try
            {
                data = lines[1];
            }
            catch
            {
                data = "";
            }
            var response = "";
            switch (cmd)
            {
                case "PLAY":
                    Play(data);
                    break;
                case "STOP":
                    Stop();
                    break;
                case "VOLUME":
                    Volume(data);
                    break;
                case "STATUS":
                    response = GetStatus();
                    break;
                case "SONG":
                    response = GetSong();
                    break;
            }

            return response;
        }

        private string GetSong()
        {
            return (radio.CurrentSong != null) ? String.Format("{0} - {1}", radio.CurrentSong.Artist, radio.CurrentSong.Title) : "";
        }

        private void Play(string data)
        {
            status = Status.WAITING;
            Task.Factory.StartNew(() =>
            {
                if (isPlaying)
                {
                    Stop();
                }
                Console.WriteLine(data);
                radio = new Radio(data);
                audio = new Audio();
                audio.onWaveProviderCreated += audio_onWaveProviderCreated;
                radio.OnStreamUpdate += radio_OnStreamUpdate;
                radio.Start();
                isPlaying = true;
            });
        }

        void radio_OnStreamUpdate(object sender, StreamUpdateEventArgs e)
        {
            status = Status.PLAYING;

            audio.OnStreamUpdate(sender, e);
        }

        IWaveProvider audio_onWaveProviderCreated(IWaveProvider provider)
        {
            volumeProvider = new VolumeWaveProvider16(provider) { Volume = volume / 100 };
            return volumeProvider;
        }

        private void Stop()
        {
            Console.WriteLine("Stopping");
            status = Status.STOP;
            Task.Factory.StartNew(() =>
            {
                try
                {
                    radio.Dispose();
                    audio.Dispose();
                }
                catch
                {
                    // ignored
                }
            });
        }

        private void Volume(string data)
        {
            try
            {
                volume = ParseInt(data, 0, 100);
            }
            catch (Exception ex)
            {
                Console.WriteLine("ERROR PARSING VOLUME - " + ex.Message);
                return;
            }

            if (!isPlaying) return;
            try
            {
                volumeProvider.Volume = volume / 100;
            }
            catch (Exception ex)
            {
                Console.WriteLine("ERROR SETTING VOLUME - " + ex.Message);
            }
        }

        public int ParseInt(string str, int min, int max)
        {
            int number;
            try
            {
                number = Convert.ToInt16(str);
                if (number > max || number < min)
                    throw new Exception("Volume out of range");
            }
            catch (Exception ex)
            {
                Console.WriteLine("ERROR PARSING NUMBER - " + ex.Message);
                throw;
            }
            return number;
        }


        private string GetStatus()
        {
            return status.ToString();
        }

    }
}
