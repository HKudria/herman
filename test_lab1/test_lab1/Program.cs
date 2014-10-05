using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test_lab1
{
    class Program
    {
        static void Main(string[] args)
        {
            string x1, a1, b1,n1;
            double a, b;
            double y=0;
            double x;
            int n;
            
            Console.Write("Введите х = ");
            x1 = Console.ReadLine();
            x = int.Parse(x1);
            if (x < 0 || x > 999)
            {
                Console.Write("Ошибочный ввод х");
                Console.ReadLine();
                Console.Write("Введите х = ");
                        x1 = Console.ReadLine();
            x = int.Parse(x1);
            if (x < 0 || x > 999)
            {
                Console.Write("Ошибочный ввод х");
                Console.ReadLine();
            }
                
            } 
                
            else
                Console.WriteLine();
                Console.Write("Введите a = ");
            a1 = Console.ReadLine();
            a = int.Parse(a1);
            Console.WriteLine();
            Console.Write("Введите b = ");
            b1 = Console.ReadLine();
            b = int.Parse(b1);
            Console.WriteLine();
            Console.Write("Введите n = ");
            n1 = Console.ReadLine();
            n = int.Parse(n1);
            if (n < 1 || n > 100)
            {
                Console.WriteLine("Ошибочный ввод n");
                Console.ReadLine();
                Environment.Exit(2); 
            } else
           
                if (x<a)
                   y = (2*Math.Sqrt(x+a))/Math.Log(x);

            if (x > a || x == a)
                y = (x * Math.Cos(a + b + x)) / (b + a);
            Console.WriteLine();
            Console.WriteLine("Результат {0}", y);
            
           Console.ReadLine();
        }

       
    }
}
