using System;
using System.Collections.Generic;
using System.IO;
using System.Xml;
using System.Xml.Serialization;
using System.Text.Json;
using Newtonsoft.Json;

namespace testing_of_Csharp
{
    [XmlInclude(typeof(Square))]
    [XmlInclude(typeof(Rectangle))]
    [XmlInclude(typeof(Circle))]
    [XmlInclude(typeof(Ellipsis))]
    
    public abstract class Figure
    {
        public string Figure_Type { get; set; }
        public double Area { get; set; }
        public uint Frame_thickness { get; set; }

        public abstract void Calc_Area();
        public abstract int Draw(int currentPos);
    }

    public class Rectangle : Figure
    {
        public double A;
        public double B;

        public Rectangle()
        {
            Figure_Type = "rectangle";
            A = B = 0;
            Frame_thickness = 0;
        }
        public Rectangle(double a,double b)
        {
            Figure_Type = "rectangle";
            A = a;
            B = b;
            Frame_thickness = 0;
            Calc_Area();
        }
        public Rectangle(double a,double b,uint frame)
        {
            Figure_Type = "rectangle";
            A = a;
            B = b;
            Frame_thickness = frame;
            Calc_Area();
        }

        public override void Calc_Area()
        {
            Area = (A + Frame_thickness) * (B + Frame_thickness);
        }

        public override string ToString()
        {
            return $"Type of figure:{Figure_Type}; Frame thickness:{Frame_thickness}; Area:{Area};";
        }

        public override int Draw(int currentPos)
        {
            if (A > Console.WindowWidth || B > Console.WindowHeight)
            {
                Console.WriteLine("figure is too big for console");
                return 1;
            }
            else
            {
                for (int i = 0; i < Console.WindowHeight / 2 - B / 2 + currentPos; i++)
                {
                    Console.WriteLine();
                }
                for (int k = 0; k < B; k++)
                {
                    for (int i = 0; i < Console.WindowWidth / 2 - A / 2; i++)
                    {
                        Console.Write(' ');
                    }
                    for (int i = 0; i < A; i++)
                    {
                        Console.Write('*');
                    }
                    Console.WriteLine();
                }
            }
            return Console.WindowHeight;
        }
    }

    public class Square : Figure
    {
        public double A { get; set; }

        public Square()
        {
            Figure_Type = "square";
            A = 0;
            Frame_thickness = 0;
        }
        public Square(double a)
        {
            Figure_Type = "square";
            A = a;
            Frame_thickness = 0;
            Calc_Area();
        }
        public Square(double a, uint frame)
        {
            Figure_Type = "square";
            A = a;
            Frame_thickness = frame;
            Calc_Area();
        }

        public override void Calc_Area()
        {
            Area = (A + Frame_thickness) * (A + Frame_thickness);
        }

        public override string ToString()
        {
            return $"Type of figure:{Figure_Type}; Frame thickness:{Frame_thickness}; Area:{Area};";
        }

        public override int Draw(int currentPos)
        {
            if (A > Console.WindowWidth || A > Console.WindowHeight)
            {
                Console.WriteLine("figure is too big for console");
                return 1;
            }
            else
            {
                for (int i = 0; i < Console.WindowHeight / 2 - A / 2 + currentPos; i++)
                {
                    Console.WriteLine();
                }
                for (int k = 0; k < A; k++)
                {
                    for (int i = 0; i < Console.WindowWidth / 2 - A / 2; i++)
                    {
                        Console.Write(' ');
                    }
                    for (int i = 0; i < A; i++)
                    {
                        Console.Write('*');
                    }
                    Console.WriteLine();
                }
            }
            return Console.WindowHeight;
        }
    }

    public class Circle : Figure
    {
        public double Radius;

        public Circle()
        {
            Figure_Type = "circle";
            Frame_thickness = 0;
            Radius = 0;
        }
        public Circle(double radius)
        {
            Figure_Type = "circle";
            Frame_thickness = 0;
            Radius = radius;
            Calc_Area();
        }
        public Circle(double radius, uint frame)
        {
            Figure_Type = "circle";
            Frame_thickness = frame;
            Radius = radius;
            Calc_Area();
        }

        public override void Calc_Area()
        {
            Area = 3.14 * Math.Pow(Radius + Frame_thickness, 2);
        }

        public override string ToString()
        {
            return $"Type of figure:{Figure_Type}; Frame thickness:{Frame_thickness}; Area:{Area}";
        }

        public override int Draw(int currentPos)
        {

            Action<int, int> write = (xp, yp) => { Console.SetCursorPosition(xp, yp); Console.Write("*"); };

            int centerX = 40, centerY = 12+currentPos, radius = Convert.ToInt32(Radius), x = -radius;
            while (x <= radius)
            {
                var y = (int)Math.Floor(Math.Sqrt(radius * radius - x * x));

                write(x + centerX, y + centerY);
                y = -y;
                write(x + centerX, y + centerY);
                x++;
            }
            Console.SetCursorPosition(0, 25 + currentPos);
            return Console.WindowHeight;
        }
    }

    public class Ellipsis : Figure
    {
        public double Major_Radius { get; set; }
        public double Minor_Radius { get; set; }

        public Ellipsis()
        {
            Figure_Type = "ellipsis";
            Major_Radius = Minor_Radius = 0;
            Frame_thickness = 0;
        }
        public Ellipsis(double major_radius,double minor_radius)
        {
            Figure_Type = "ellipsis";
            Major_Radius = major_radius;
            Minor_Radius = minor_radius;
            Frame_thickness = 0;
            Calc_Area();
        }
        public Ellipsis(double major_radius, double minor_radius,uint frame)
        {
            Figure_Type = "ellipsis";
            Major_Radius = major_radius;
            Minor_Radius = minor_radius;
            Frame_thickness = frame;
            Calc_Area();
        }

        public override void Calc_Area()
        {
            Area = 3.14 * (Major_Radius + Frame_thickness) * (Minor_Radius + Frame_thickness);
        }

        public override string ToString()
        {
            return $"Type of figure:{Figure_Type}; Frame thickness:{Frame_thickness}; Area:{Area}";
        }

        public override int Draw(int currentPos)
        {
            double width = Major_Radius * 2,height=Minor_Radius*2;
            if (height > Console.WindowHeight || width > Console.WindowWidth)
            {
                Console.WriteLine("figure is too big for console");
                return 1;
            }
            int centerX = 40, centerY = 12 + currentPos;
            for (int i = 0; i < width; i++)
            {
                int dx = Convert.ToInt32(i - width / 2);
                int x = centerX + dx;

                int h = (int)Math.Round(height * Math.Sqrt(width * width / 4.0 - dx * dx) / width);
                for (int dy = 1; dy <= h; dy++)
                {
                    Console.SetCursorPosition(x, centerY + dy);
                    Console.Write('*');
                    Console.SetCursorPosition(x, centerY - dy);
                    Console.Write('*');
                }

                if (h >= 0)
                {
                    Console.SetCursorPosition(x, centerY);
                    Console.Write('*');
                }
                Console.Write('*');
            }
            Console.SetCursorPosition(0, 25 + currentPos);
            return Console.WindowHeight;
        }
    }

    public class Graphics_editor
    {
        public double AvgArea { get; set; }
        public List<Figure> Figures { get; } = new List<Figure>();
        public void Sorting()
        {
            Figures.Sort(delegate (Figure x, Figure y)
            {
                if (x.Area == y.Area)
                    return x.Frame_thickness.CompareTo(y.Frame_thickness);
                else
                    return x.Area.CompareTo(y.Area);
            });
        }

    }

    class Program
    {
        static public void MENU()
        {
            Console.WriteLine("this is menu of programm:");
            Console.WriteLine("1) input a figure");
            Console.WriteLine("2) sort and display");
            Console.WriteLine("3) show the type of the first three figures");
            Console.WriteLine("4) draw last two figures");
            Console.WriteLine("5) serialize list in xml and json");
            Console.WriteLine("0) close");
            Console.WriteLine("!) get a menu");
        }

        static public string ReplaceDotOnComma(string str)
        {
            if(str.Contains("."))
            {
                str = str.Replace(".", ",");
                return str;
            }
            return str;
        }

        static void Main(string[] args)
        {
            Graphics_editor editor = new Graphics_editor
            {
                AvgArea = 0.0
            };
            /*editor.Figures.Add(new Square(10,2));
            editor.Figures.Add(new Circle(5,6));
            editor.Figures.Add(new Rectangle(10,2,6));
            editor.Figures.Add(new Rectangle(12, 12, 0));
            editor.Figures.Add(new Ellipsis(20, 6, 4));*/
            MENU();
            Console.Write('>');
            string choice = Console.ReadLine();
            while(true)
            {
                switch (choice)
                {
                    case "1":
                        {
                            Console.Clear();
                            string choice1;
                            Console.WriteLine("1) via console\n2) via xml or json file");
                            Console.Write(">");
                            choice1 = Console.ReadLine();
                            switch(choice1)
                            {
                                case "1":
                                    {
                                        Console.WriteLine("choose type of figure:");
                                        Console.Write("1)square\n2)rectangle\n3)circle\n4)ellipsis\n");
                                        choice1 = Console.ReadLine();
                                        switch (choice1)
                                        {
                                            case "1":
                                                {
                                                    double num_a;
                                                    uint num_frame;
                                                    Console.Write("enter side size: ");
                                                    num_a = Convert.ToDouble(Console.ReadLine());
                                                    Console.Write("enter frame thickness: ");
                                                    num_frame = Convert.ToUInt32(Console.ReadLine());
                                                    editor.Figures.Add(new Square(num_a, num_frame));
                                                    break;
                                                }
                                            case "2":
                                                {
                                                    double num_a, num_b;
                                                    uint num_frame;
                                                    num_a = Convert.ToDouble(Console.ReadLine());
                                                    num_b = Convert.ToDouble(Console.ReadLine());
                                                    num_frame = Convert.ToUInt32(Console.ReadLine());
                                                    editor.Figures.Add(new Rectangle(num_a, num_b, num_frame));
                                                    break;
                                                }
                                            case "3":
                                                {
                                                    double num_rad = Convert.ToDouble(Console.ReadLine());
                                                    uint num_frame = Convert.ToUInt32(Console.ReadLine());
                                                    editor.Figures.Add(new Circle(num_rad, num_frame));
                                                    break;
                                                }
                                            case "4":
                                                {
                                                    double maj_rad = Convert.ToDouble(Console.ReadLine()), min_rad = Convert.ToDouble(Console.ReadLine());
                                                    uint num_frame = Convert.ToUInt32(Console.ReadLine());
                                                    editor.Figures.Add(new Ellipsis(maj_rad, min_rad, num_frame));
                                                    break;
                                                }
                                        }
                                        for (int i = 0; i < editor.Figures.Count; i++)
                                        {
                                            editor.AvgArea += editor.Figures[i].Area;
                                        }
                                        editor.AvgArea /= editor.Figures.Count;
                                        break;
                                    }
                                case "2":
                                    {
                                        Console.Clear();
                                        Console.WriteLine("1) xml\n2) json");
                                        Console.Write(">");
                                        choice1 = Console.ReadLine();
                                        switch(choice1)
                                        {
                                            case "1":
                                                {
                                                    Console.Write("input name of xml file: ");
                                                    string NameOfFile = Console.ReadLine();
                                                    while (!NameOfFile.Contains(".xml"))
                                                    {
                                                        Console.WriteLine("error");
                                                        NameOfFile = Console.ReadLine();
                                                    }
                                                    uint tempFrame = 0;
                                                    double temp1 = 0.0, temp2 = 0.0;
                                                    try
                                                    {
                                                        XmlDocument xDoc = new XmlDocument();
                                                        xDoc.Load(NameOfFile);
                                                        XmlElement xRoot = xDoc.DocumentElement;
                                                        foreach (XmlElement xnode in xRoot)
                                                        {
                                                            if (xnode.Attributes.Count > 0)
                                                            {
                                                                XmlNode attr = xnode.Attributes.GetNamedItem("xsi:type");
                                                                if (attr != null)
                                                                {
                                                                    switch (attr.Value)
                                                                    {
                                                                        case "Square":
                                                                            {
                                                                                foreach (XmlNode childnode in xnode.ChildNodes)
                                                                                {
                                                                                    switch (childnode.Name)
                                                                                    {
                                                                                        case "Area":
                                                                                            {
                                                                                                editor.AvgArea += Convert.ToDouble(ReplaceDotOnComma(childnode.InnerText));
                                                                                                break;
                                                                                            }
                                                                                        case "A":
                                                                                            {
                                                                                                temp1 = Convert.ToDouble(ReplaceDotOnComma(childnode.InnerText));
                                                                                                break;
                                                                                            }
                                                                                        case "Frame_thickness":
                                                                                            {
                                                                                                tempFrame = Convert.ToUInt32(ReplaceDotOnComma(childnode.InnerText));
                                                                                                break;

                                                                                            }
                                                                                    }
                                                                                }
                                                                                editor.Figures.Add(new Square(temp1, tempFrame));
                                                                                break;
                                                                            }
                                                                        case "Rectangle":
                                                                            {
                                                                                foreach (XmlNode childnode in xnode.ChildNodes)
                                                                                {
                                                                                    switch (childnode.Name)
                                                                                    {
                                                                                        case "Area":
                                                                                            {
                                                                                                editor.AvgArea += Convert.ToDouble(ReplaceDotOnComma(childnode.InnerText));
                                                                                                break;
                                                                                            }
                                                                                        case "Frame_thickness":
                                                                                            {
                                                                                                tempFrame = Convert.ToUInt32(ReplaceDotOnComma(childnode.InnerText));
                                                                                                break;
                                                                                            }
                                                                                        case "A":
                                                                                            {
                                                                                                temp1 = Convert.ToDouble(ReplaceDotOnComma(childnode.InnerText));
                                                                                                break;
                                                                                            }
                                                                                        case "B":
                                                                                            {
                                                                                                temp2 = Convert.ToDouble(ReplaceDotOnComma(childnode.InnerText));
                                                                                                break;
                                                                                            }
                                                                                    }
                                                                                }
                                                                                editor.Figures.Add(new Rectangle(temp1, temp2, tempFrame));
                                                                                break;
                                                                            }
                                                                        case "Ellipsis":
                                                                            {
                                                                                foreach (XmlNode childnode in xnode.ChildNodes)
                                                                                {
                                                                                    switch (childnode.Name)
                                                                                    {
                                                                                        case "Area":
                                                                                            {
                                                                                                editor.AvgArea += Convert.ToDouble(ReplaceDotOnComma(childnode.InnerText));
                                                                                                break;
                                                                                            }
                                                                                        case "Frame_thickness":
                                                                                            {
                                                                                                tempFrame = Convert.ToUInt32(ReplaceDotOnComma(childnode.InnerText));
                                                                                                break;
                                                                                            }
                                                                                        case "Major_Radius":
                                                                                            {
                                                                                                temp1 = Convert.ToDouble(ReplaceDotOnComma(childnode.InnerText));
                                                                                                break;
                                                                                            }
                                                                                        case "Minor_Radius":
                                                                                            {
                                                                                                temp2 = Convert.ToDouble(ReplaceDotOnComma(childnode.InnerText));
                                                                                                break;
                                                                                            }
                                                                                    }
                                                                                }
                                                                                editor.Figures.Add(new Ellipsis(temp1, temp2, tempFrame));
                                                                                break;
                                                                            }
                                                                        case "Circle":
                                                                            {
                                                                                foreach (XmlNode childnode in xnode.ChildNodes)
                                                                                {
                                                                                    switch (childnode.Name)
                                                                                    {
                                                                                        case "Area":
                                                                                            {
                                                                                                editor.AvgArea += Convert.ToDouble(ReplaceDotOnComma(childnode.InnerText));
                                                                                                break;
                                                                                            }
                                                                                        case "Frame_thickness":
                                                                                            {
                                                                                                tempFrame = Convert.ToUInt32(ReplaceDotOnComma(childnode.InnerText));
                                                                                                break;
                                                                                            }
                                                                                        case "Radius":
                                                                                            {
                                                                                                temp1 = Convert.ToDouble(ReplaceDotOnComma(childnode.InnerText));
                                                                                                break;
                                                                                            }
                                                                                    }
                                                                                }
                                                                                editor.Figures.Add(new Circle(temp1, tempFrame));
                                                                                break;
                                                                            }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                    catch
                                                    {
                                                        Console.WriteLine("file is empty");
                                                    }
                                                    break;
                                                }
                                            case "2":
                                                {
                                                    throw new NotImplementedException("not done :(");
                                                }
                                        }
                                        break;
                                    }

                            }
                            break;
                        }
                    case "2":
                        {
                            Console.Clear();
                            editor.Sorting();
                            foreach (Figure aFigure in editor.Figures)
                            {
                                Console.WriteLine(aFigure);
                            }
                            Console.WriteLine($"Average area: {editor.AvgArea}");
                            break;
                        }
                    case "3":
                        {
                            Console.Clear();
                            for (int i = 0; i < 3; i++)
                            {
                                Console.WriteLine(editor.Figures[i].Figure_Type);
                            }
                            break;
                        }
                    case "4":
                        {
                            Console.Clear();
                            int currentPos = 0;
                            if (editor.Figures.Count <= 1)
                            {
                                if (editor.Figures.Count == 0)
                                {
                                    break;
                                }
                                for (int i = 0; i < editor.Figures.Count; i++)
                                {
                                    currentPos = editor.Figures[i].Draw(currentPos);
                                }
                                break;
                            }
                            for (int i = editor.Figures.Count - 1; i >= editor.Figures.Count - 2; i--)
                            {

                                currentPos = editor.Figures[i].Draw(currentPos);
                            }
                            break;
                        }
                    case "5":
                        {
                            Console.Clear();
                            string NameOfFile;
                            Console.WriteLine("1) in xml\n2) in json");
                            Console.Write('>');
                            string choice5 = Console.ReadLine();
                            Console.Clear();
                            switch(choice5)
                            {
                                case "1":
                                    {
                                        Console.Write("input name of xml file: ");
                                        NameOfFile = Console.ReadLine();
                                        while (!NameOfFile.Contains(".xml"))
                                        {
                                            Console.WriteLine("error");
                                            NameOfFile = Console.ReadLine();
                                        }
                                        XmlSerializer serializer = new XmlSerializer(typeof(List<Figure>));
                                        TextWriter writer = new StringWriter();
                                        serializer.Serialize(writer, editor.Figures);
                                        Console.WriteLine(writer.ToString());
                                        using (FileStream fs = new FileStream(NameOfFile, FileMode.OpenOrCreate))
                                        {
                                            serializer.Serialize(fs, editor.Figures);
                                        }
                                        break;
                                    }
                                case "2":
                                    {
                                        File.WriteAllText("testinJson.json", System.Text.Json.JsonSerializer.Serialize(editor.Figures));
                                        Console.WriteLine(System.Text.Json.JsonSerializer.Serialize(editor.Figures));
                                        break;
                                    }
                            }
                            break;
                        }
                    case "0":
                        {
                            return;
                        }
                    case "!":
                        {
                            Console.Clear();
                            MENU();
                            break;
                        }
                }
                Console.Write('>');
                choice = Console.ReadLine();
            }
            
            //Console.ReadKey();
        }
    }
}