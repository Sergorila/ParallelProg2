//My_Task_A.cpp
#include "My_Task.h"
#include <cmath>
#include <algorithm>

double My_Task(int k)
{
	double ans = 0;
	for (int i = 1; i <= std::max(20, 20 * abs((int)k)); i++)
	{
		for (int j = 1; j <= std::max(20, 20 * abs((int)k)); j++)
		{
			ans += (k*k*j/(k*k+i*i+j*j*j))*sin((i+2*j)*k);
		}
	}
	return ans;
}