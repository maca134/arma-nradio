using System;
using System.Diagnostics;
using System.IO;
using System.Reflection;

namespace TestConsole
{
    class Program
    {
        private static readonly ARMAExt _ext = new ARMAExt();

        static void Main(string[] args)
        {
            _ext.Load(Path.Combine(Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location), "nRadio.dll"));
            while (true)
            {
                Console.Write("Enter Command: ");
                string cmd = Console.ReadLine();
                if (cmd == "")
                {
                    _ext.Unload();
                    break;
                }

                Stopwatch watch = Stopwatch.StartNew();
                cmd = cmd + "\n";
                string result = _ext.Invoke(cmd);
                watch.Stop();
                long elapsedMs = watch.ElapsedMilliseconds;
                Console.WriteLine("Command took {0} ms to run", elapsedMs);
                Console.WriteLine(result);
                Console.WriteLine("--------------");
            }

        }
    }
}
