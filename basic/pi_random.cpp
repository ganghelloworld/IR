#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>


static const long PRECISION = 10000000;
double get_random()
{
	srand(time(NULL));
	return double(rand() % (PRECISION+1)) / PRECISION;
}

int main()
{
	double x, y, pi;

	long k = 0, n = 0;
	/*
	for(int i = 0; i < 10; i++)
	{
		std::cout << get_random() << std::endl;
		usleep(500000);
	}
	return 0;
	*/
	while(1)
	{
		sleep(1);
		x = get_random();
		sleep(1);
		y = get_random();
		if(pow(x, 2) + pow(y, 2) <= 1)
		{
			k++;
		}
		n++;
		pi = 4 * k / (double)n;
		std::cout << "k/n = " << k << "/" << n << "\t" << pi << std::endl;
	}
}
