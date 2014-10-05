using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

// ЕМПИ Разработал Кудря Герман група ЗПЗС-1444
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
                   
                        arr[l] = array[i, j]; //перевод в одинарный масив
                        l++;
                        Console.Write("{0}\t", array[i,j]);
                                           
                }
            }

            //Vuvod otsortirovanogo masiva v stroky
            Console.WriteLine();
            Array.Sort(arr);
            foreach (var item in arr)
            Console.Write(item);
            // Подсчет повторений елементов масива
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
            //Среднее арифметическое строки
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

            //Среднее арифметическое столбца
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

            //Медиана
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

            //Мода масива 
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
            double MatOj = 0;
            double Disp = 0;
            //Дисперсия
            for (int i = 0; i < arr.Length; i++)
                MatOj = arr[i] + MatOj;
            MatOj = MatOj / arr.Length;

            for (int i = 0; i < arr.Length; i++)
                Disp = Math.Pow((arr[i] - MatOj), 2) + Disp;
            Disp = Disp / arr.Length;

            Console.WriteLine("Дисперсия масива = {0}", Disp);
            // Отклонение
            Console.WriteLine("Среднее квадратическое отклонение = {0}", Math.Sqrt(Disp));
            Console.ReadLine();
                    
        }
       
    }
    

}
