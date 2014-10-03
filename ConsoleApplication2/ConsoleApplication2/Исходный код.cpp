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
		setlocale(0, "");
		srand(unsigned(time(NULL)));
		int N, M;
		cout << "Введите размер матрицы: ";
		cin >> N >> M;
		int ** A = new int *[N];
		for (int i = 0; i < N; i++)
			A[i] = new int[M];

		for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			A[i][j] = ((rand() % 10));


		cout << "Вот Ваша матрица:" << endl ;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
				cout << A[i][j] << " ";
			cout << endl;
		}

		cout << "Сортировка:" << endl ;
		int tmp;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++)
				std::cout << " " << A[i][j];
		}

		

		cout << endl;
		for (int i = 0; i < N; i++)
			delete[] A[i];
		delete[] A;
		
		system("pause");
		return 0;
	}
	else {
		std::cout << "/nO_o";
		system("pause");
		return 0;
	}

 
	
}


