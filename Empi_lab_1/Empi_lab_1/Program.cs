using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;


namespace Empi_lab_1
{
    class Program
    {
        static void Main(string[] args)
        {

            int l = 0;
            int j = 0;
            int[,] array = new int[,] { { 5, 4, 2, 7, 8, 5 ,2, 9, 4, 2}, {6, 3, 6, 8, 2, 7, 5, 4, 2, 7}, {4, 7, 4, 1, 3, 6, 8, 9, 4, 6}, {8, 6, 4, 8, 3, 5, 9, 6, 3, 4} };
            int[] arr = new int[40];
            for (int i = 0; i<4; i++)
            {
                for (j = 0; j < 10; j++)
                {
                   
                        arr[l] = array[i, j];
                        l++;
                        Console.Write("{0}\t", array[i,j]);
                                           
                }
            }

            //Vuvod otsortirovanogo masiva v stroky
            Console.WriteLine();
            Array.Sort(arr);
            foreach (var item in arr)
            Console.Write(item);

            int Count = 0;

            for (int i = 0; i < arr.Length; i++)
            {
                for (j = 0; j < arr.Length; j++)
                {
                    if (arr[i] == arr[j])
                        Count++;
                                       
                }

                Console.WriteLine("Элемент {0} встречается в массиве {1} раз", arr[i], Count);
                Count = 0;
                
            }
            float c = 0;
            float d = 0;
            for (int i = 0; i < 4; i++)
            {
                for (j = 0; j < 10; j++)
                {
                    c += array[i, j];
                }
                d = c / 10;
                Console.WriteLine("Среднее арифметическое {0} строки = {1}", i + 1, d);
               
            }
            Console.WriteLine();

            c = 0;
            d = 0;
            for (int i = 0; i < 10; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    c += array[j, i];
                }
                d = c / 4;
                c = 0;
                Console.WriteLine("Среднее арифметическое {0} столбца = {1}", i + 1, d);
            }

            double h = 0;
            for (int i = 0; i < arr.Length; i++)
            { Array.Sort(arr);
                int g = arr.Length - 1;
                if (g % 2 == 0) 
                {
                    h = (arr[g] + arr[g]) / 2;
                }
                else h = arr[g];
            }
            Console.WriteLine("Медиана = {0}", h);


            int max = arr[0];
             int cmax = 0, rmax = 0;
            for (int i = 0; i < arr.Length; i++)
            {
                if (cmax > rmax)
                {
                    rmax = cmax;
                    max = arr[i - 1];
                }
                cmax = 0;
                for (j = i; j < arr.Length; j++)
                    if (arr[j] == arr[i])
                        cmax++;
            }
            Console.WriteLine("Мода масива {0} количество повторений = {1}", max, rmax);


            Console.ReadLine();
            
            
        }
       
    }
    

}
