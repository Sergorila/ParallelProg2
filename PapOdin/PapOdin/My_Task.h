// My_Task.h
#include <math.h>
double My_Task(int k)
{
	double ans = 0;
	int end = 20 * abs(k);
	for (int i = 1; i <= end; i++)
	{
		for (int j = 1; j <= end; j++)
		{
			ans += ((k * k * (i + j)) / (k * k + pow(i, 3) + pow(j, 3))) * cos(i * k) * sin(j * k);
		}
	}
	return ans;
}