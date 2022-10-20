//My_Task_A.cpp
#include "My_Task.h"
#include <cmath>
#include <algorithm>
#define N1 3

double My_Task1(int k)
{
	double ans = 0;
	for (int i = 1; i <= N1; i++)																		    
	{
		for (int j = 1; j <= N1; j++)
		{
			for (int n = 1; n <= N1; j++)
			{
				ans += (k*k + i)/(1 + k*k + i*i*i+j*j+n*n);
			}
		}
	}
	return ans;
}