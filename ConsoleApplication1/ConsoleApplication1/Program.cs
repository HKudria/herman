using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите число элементов массива A1");
            int size = int.Parse(Console.ReadLine());
            int[] A1 = new int[size];
            Arrs.CreateOneDimAr(A1);
            Arrs.PrintAr1("A1", A1); 
        }
    }
}
