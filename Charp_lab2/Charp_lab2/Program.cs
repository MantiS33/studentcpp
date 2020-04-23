using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Text.RegularExpressions;
using System.IO;
using CsQuery;

namespace Charp_lab2
{
    internal class WebAnalysis
    {
        public delegate void Analysator(string URI, int depth,string src,string alt);
        public event Analysator Notify;

        private bool Crutch = false;
        private int Depth { get; set; }
        
        public void Analysis(string URI,int depth)
        {
            if(depth>=0)
            {
                if (Crutch != true)
                {
                    Depth = 0;
                    Crutch = true;
                }
                else
                {
                    Depth += 1;
                }
                WebClient client = new WebClient();
                string page = client.DownloadString(new Uri($"{URI}"));

                CQ cq = CQ.Create(page);
                foreach (IDomObject obj in cq.Find("img"))
                {
                    Notify?.Invoke(URI, Depth, obj.GetAttribute("src"), obj.GetAttribute("alt"));
                }

                if (depth > 0)
                {
                    foreach (IDomObject obj in cq.Find("a"))
                    {
                        if (obj.GetAttribute("href") != null && obj.GetAttribute("href").Contains(URI) && (obj.GetAttribute("href") != URI))
                        {
                            depth = depth - 1;
                            Analysis(obj.GetAttribute("href"), depth);
                        }
                    }
                }
            }
            
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int depth;
            var web = new WebAnalysis();
            string choose;
            Console.WriteLine("1)print\n2)save");
            choose=Console.ReadLine();
            switch(choose)
            {
                case "1":
                    {
                        Console.Clear();
                        Console.Write("inpute the depth:");
                        depth = Convert.ToInt32(Console.ReadLine());
                        web.Notify += Display;
                        web.Analysis("https://ru.wikipedia.org", depth);
                        break;
                    }
                case "2":
                    {
                        Console.Clear();
                        Console.Write("inpute the depth:");
                        depth = Convert.ToInt32(Console.ReadLine());
                        FileStream fs = new FileStream("testing.csv", FileMode.Append);
                        StreamWriter sw = new StreamWriter(fs);
                        sw.Write("URI;src;alt;depth\n");
                        sw.Close();
                        fs.Close();
                        web.Notify -= Display;
                        web.Notify += Print;
                        web.Analysis("https://ru.wikipedia.org", depth);
                        break;
                    }
            }
            
            Console.ReadKey();
        }

        private static void Print(string URI, int depth, string src, string alt)
        {
            string str = URI + ";" + src + ";" + alt + ";" + Convert.ToString(depth) + "\n";
            FileStream fs = new FileStream("testing.csv", FileMode.Append);
            StreamWriter sw = new StreamWriter(fs);
            sw.Write(str);
            sw.Close();
            fs.Close();
        }

        private static void Display(string URI, int depth, string src, string alt)
        {
            switch(depth)
            {
                case 0:
                    {
                        Console.WriteLine($"{URI}:");
                        Console.WriteLine("||" + src);
                        Console.WriteLine("||" + alt);
                        Console.WriteLine("||" + depth);
                        break;
                    }
                case 1:
                    {
                        Console.WriteLine($"||{URI}:");
                        Console.WriteLine("|-|" + src);
                        Console.WriteLine("|-|" + alt);
                        Console.WriteLine("|-|" + depth);
                        break;
                    }
                case 2:
                    {
                        Console.WriteLine($"|-|{URI}:");
                        Console.WriteLine("|--|" + src);
                        Console.WriteLine("|--|" + alt);
                        Console.WriteLine("|--|" + depth);
                        break;
                    }
                case 3:
                    {
                        Console.WriteLine($"|--|{URI}:");
                        Console.WriteLine("|---|" + src);
                        Console.WriteLine("|---|" + alt);
                        Console.WriteLine("|---|" + depth);
                        break;
                    }
            }
        }
    }
}