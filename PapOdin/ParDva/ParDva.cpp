//parallel_transform.cpp
#include <locale.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <ppl.h>
#include <iostream>
#include "My_Task_A.h"
#include <cmath>
#include <deque>
#include <list>
#define N1 2000
#define N2 50

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, ".ACP");
	std::vector<double> X0(N1);
	std::deque<double> dX0(N1);
	std::list<double> lX0(N1);
	for (int k = 0; k < N1; k++)
	{
		X0[k] = 100 * cos(k);
		dX0.push_back(X0[k]);
		lX0.push_back(X0[k]);
	}
		
	std::vector<double> Y0(N1);
	std::deque<double> dY0(N1);
	std::list<double> lY0(N1);
	for (int k = 0; k < N1; k++)
	{
		Y0[k] = 100 * cos(k);
		dY0.push_back(X0[k]);
		lY0.push_back(X0[k]);
	}


	double Time = clock();
	std::transform(X0.begin(), X0.end(), Y0.begin(), [](double x) -> double {return My_Task_A(x); });
	Time = (clock() - Time) / CLOCKS_PER_SEC;
	std::cout << "Vector Преобразование завершено" << std::endl
		<< "Время посл. обр: " << Time << " сек." << std::endl;
	Time = clock();
	std::transform(dX0.begin(), dX0.end(), dY0.begin(), [](double x) -> double {return My_Task_A(x); });
	Time = (clock() - Time) / CLOCKS_PER_SEC;
	std::cout << "Deque Преобразование завершено" << std::endl
		<< "Время посл. обр: " << Time << " сек." << std::endl;
	Time = clock();
	std::transform(lX0.begin(), lX0.end(), lY0.begin(), [](double x) -> double {return My_Task_A(x); });
	Time = (clock() - Time) / CLOCKS_PER_SEC;
	std::cout << "List Преобразование завершено" << std::endl
		<< "Время посл. обр: " << Time << " сек." << std::endl;

	Time = clock();
	concurrency::parallel_transform(X0.begin(), X0.end(), Y0.begin(), [](double x) -> double {return My_Task_A(x); });
	Time = (clock() - Time) / CLOCKS_PER_SEC;
	std::cout << " Vector Преобразование завершено" << std::endl
		<< "Время парал. обр.: " << Time << " сек." << std::endl;
	Time = clock();
	concurrency::parallel_transform(dX0.begin(), dX0.end(), dY0.begin(), [](double x) -> double {return My_Task_A(x); });
	Time = (clock() - Time) / CLOCKS_PER_SEC;
	std::cout << " Deque Преобразование завершено" << std::endl
		<< "Время парал. обр.: " << Time << " сек." << std::endl;
	Time = clock();
	concurrency::parallel_transform(lX0.begin(), lX0.end(), lY0.begin(), [](double x) -> double {return My_Task_A(x); });
	Time = (clock() - Time) / CLOCKS_PER_SEC;
	std::cout << " List Преобразование завершено" << std::endl
		<< "Время парал. обр.: " << Time << " сек." << std::endl;

	return 0;
}