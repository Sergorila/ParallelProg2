//parallel_transform.cpp
#include <locale.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <ppl.h>
#include <iostream>
#include "My_Task.h"
#include <cmath>
#define N1 10
#define N2 50

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, ".ACP");
	std::vector<double> X0(N1);
	for (int k = 0; k < N1; k++)
		X0[k] = k;
	std::vector<double> Y0(N1);
	for (int k = 0; k < N1; k++)
	{
		Y0[k] = k;
		std::cout << Y0[k] << std::endl;
	}
		
	std::vector<double> Y(Y0);//Конструируем копию

	double Time = clock();
	std::transform(X0.begin(), X0.end(), Y.begin(), [](int x) -> double {return My_Task1(x); });
	Time = (clock() - Time) / CLOCKS_PER_SEC;
	std::cout << "Преобразование завершено" << std::endl
		<< "Время посл. обр: " << Time << " сек." << std::endl;

	Y = Y0;
	Time = clock();
	concurrency::parallel_transform(X0.begin(), X0.end(), Y.begin(), [](int x) -> double {return My_Task1(x); });
	Time = (clock() - Time) / CLOCKS_PER_SEC;
	std::cout << "Преобразование завершено" << std::endl
		<< "Время парал. обр.: " << Time << " сек." << std::endl;
}