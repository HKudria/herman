#include <stdio.h>
#include <Windows.h>
#include <math.h>
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;


int main(int argc, char* argv[])
{
	int vubor;
	printf ("Vubor zapolneniya masiva");
	printf  ("\n1 - avto");
	printf ("\n2 - hands");
	std::cin >> vubor;

	if (vubor == 1)
	{
		int l, m;
		std::cout << "Kol strok = ";
		std::cin >> l;
		std::cout << "Kol slolb = ";
		std::cin >> m;
		srand(time(0)); // генерация случайных чисел
		// динамическое создание двумерного массива вещественных чисел на десять элементов
		int **ptrarray = new int*[l]; // две строки в массиве
		for (int count = 0; count < l; count++)
			ptrarray[count] = new int[m]; // и пять столбцов
		// заполнение массива
		for (int count_row = 0; count_row < l; count_row++)
		for (int count_column = 0; count_column < m; count_column++)
			ptrarray[count_row][count_column] = (rand() % 10 + 1) / int((rand() % 10 + 1)); //заполнение массива случайными числами с масштабированием от 1 до 10
		// вывод массива
		for (int count_row = 0; count_row < l; count_row++)
		{
			for (int count_column = 0; count_column < m; count_column++)
				cout << setw(4) << setprecision(l) << ptrarray[count_row][count_column] << "   ";
			cout << endl;
		}
		
		system("pause");
		return 0;
	}
	else {
		std::cout << "/nO_o";
		system("pause");
		return 0;
	}
 
	
}