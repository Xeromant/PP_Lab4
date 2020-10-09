#include "omp.h"
#include "Vector.h"
#include <iostream>
#include "Windows.h"
#include <ctime>


Vector FindMax(Vector vecArray[], int n)
{
	double maxLength = 0;

	for (int i = 0; i < n; i++)
	{
		vecArray[i].length = vecArray[i].GetLength();
		if (vecArray[i].length >= maxLength)
		{
			maxLength = vecArray[i].length;
		}
	}
	for (int i = 0; i < n; i++)
	{

		if (vecArray[i].length == maxLength)
		{
			return vecArray[i];
		}
	}
}

int main()
{
	setlocale(LC_ALL, "");

	int n;
	printf("Введите размер массивов\n");
	std::cin >> n;


	Vector* vecArray = new Vector[n];
	for (int i = 0; i < n; i++)
	{
		vecArray[i].x = rand() % 10000 + 1;
		vecArray[i].y = rand() % 10000 + 1;
	}

	Vector* vecArray1 = new Vector[n];
	for (int i = 0; i < n; i++)
	{
		vecArray1[i].x = rand() % 10000 + 1;
		vecArray1[i].y = rand() % 10000 + 1;
	}

	Vector Max = FindMax(vecArray, n);
	printf("Максимальный вектор 1 массива: (0, 0); (%d, %d)\nЕго длина = %.2f\n", Max.x, Max.y, Max.length);

	Vector Max1 = FindMax(vecArray1, n);
	printf("Максимальный вектор 2 массива: (0, 0); (%d, %d)\nЕго длина = %.2f\n", Max1.x, Max1.y, Max1.length);

	double sumScalar = 0;
	unsigned int startTime = clock();
#pragma omp parallel 
	{
#pragma omp for schedule(static, 1500)
	for (int i = 0; i < n; i++)
	{
		sumScalar += vecArray[i].Scalar(vecArray[i], vecArray1[i]);
	}
	}
	unsigned int endTime = clock();
	unsigned int searchTime = endTime - startTime;
	printf("(Параллельно)Время суммирования = %d\n", searchTime);
	printf("Общее скалярное произведение = %.3f\n", sumScalar);

	double sumScalar1 = 0;
	unsigned int startTime1 = clock();
	{
		for (int i = 0; i < n; i++)
		{
			sumScalar1 += vecArray[i].Scalar(vecArray[i], vecArray1[i]);
		}
	}
	unsigned int endTime1 = clock();
	unsigned int searchTime1 = endTime1 - startTime1;

	printf("Время суммирования = %d\n", searchTime1);
	printf("Общее скалярное произведение = %.3f", sumScalar);






}

