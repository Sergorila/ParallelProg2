//My_Task_A.cpp
#include "My_Task_A.h"
#include <cmath>
#include <algorithm>

double My_Task_A(double k)
{
	double ans = 0;
	for (int i = 1; i <= std::max(20, 20 * abs((int)k)); i++)
	{
		for (int j = 1; j <= std::max(20, 20 * abs((int)k)); j++)
		{
			ans += ((k * k * (i + j)) / (k * k + pow(i, 3) + pow(j, 3))) * cos(i * k) * sin(j * k);
		}
	}
	return ans;
}