using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace testing_of_Csharp
{
    public abstract class Figure
    {
        public string Figure_Type { get; set; }
        public double Area { get; set; }
        public int Frame_thickness { get; set; }

        public abstract void Calc_Area();
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
        public Square(double a, int frame)
        {
            Figure_Type = "square";
            A = a;
            Frame_thickness = frame;
            Calc_Area();
        }

        public override void Calc_Area()
        {
            Area = A * A + Frame_thickness;
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
        public Circle(double radius, int frame)
        {
            Figure_Type = "circle";
            Frame_thickness = frame;
            Radius = radius;
            Calc_Area();
        }

        public override void Calc_Area()
        {
            Area = 3.14 * Math.Pow(Radius, 2) + Frame_thickness;
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
        public Ellipsis(double major_radius, double minor_radius,int frame)
        {
            Figure_Type = "ellipsis";
            Major_Radius = major_radius;
            Minor_Radius = minor_radius;
            Frame_thickness = frame;
            Calc_Area();
        }

        public override void Calc_Area()
        {
            Area = 3.14 * Major_Radius * Minor_Radius + Frame_thickness;
        }

        public override string ToString()
        {
            return $"Type of figure:{Figure_Type}; Frame thickness:{Frame_thickness}; Area:{Area}";
        }
    }

    public class Graphics_editor
    {
        public List<Figure> Figures { get; } = new List<Figure>();
    }

    class Program
    {
        static void Main(string[] args)
        {
            Square square = new Square(10,2);
            Circle circle = new Circle(6, 3);
            Ellipsis ellipsis = new Ellipsis(5, 3, 5);
            Console.WriteLine(square.ToString());
            Console.WriteLine(circle.ToString());
            Console.WriteLine(ellipsis.ToString());
            Console.ReadKey();
        }
    }
}