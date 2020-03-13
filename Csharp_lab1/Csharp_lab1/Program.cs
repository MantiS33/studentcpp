using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace testing_of_Csharp
{
    /*[XmlInclude(typeof(Square))]
    [XmlInclude(typeof(Rectangle))]
    [XmlInclude(typeof(Circle))]
    [XmlInclude(typeof(Ellipsis))]*/
    public abstract class Figure
    {
        public string Figure_Type { get; set; }
        public double Area { get; set; }
        public uint Frame_thickness { get; set; }

        public abstract void Calc_Area();
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
    }

    public class Graphics_editor
    {
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
        void Menu()
        {

        }

        static void Main(string[] args)
        {
            Graphics_editor editor = new Graphics_editor();

            editor.Figures.Add(new Square(10,2));
            editor.Figures.Add(new Circle(5,6));
            editor.Figures.Add(new Rectangle(10,2,6));
            editor.Figures.Add(new Rectangle(12, 12, 0));
            editor.Figures.Add(new Ellipsis(20, 30, 4));

            
            Console.WriteLine("Choose the function:");
            string choice = Console.ReadLine();
            switch (choice)
            {
                case "1":
                    {
                        editor.Sorting();
                        foreach (Figure aFigure in editor.Figures)
                        {
                            Console.WriteLine(aFigure.ToString());
                        }
                        break;
                    }
                case "2":
                    {
                        for(int i=0; i<3;i++)
                        {
                            Console.WriteLine(editor.Figures[i]);
                        }
                        break;
                    }
                case "3":
                    {
                        for(int i=editor.Figures.Count-1;i>=editor.Figures.Count-2;i--)
                        {
                            Console.WriteLine(editor.Figures[i]);
                        }
                        break;
                    }
            }

            Console.ReadKey();
        }
    }
}