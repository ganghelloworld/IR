#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
using namespace std;

static const long PRECISION = 1000000000;

inline double get_random()
{
	return double(rand() % (PRECISION+1)) / PRECISION;
}

int main()
{
	double x, y, pi;

	long k = 0, n = 0;
	srand(time(NULL));
	/*
	for(int i = 0; i < 100; i++)
	{
		std::cout << get_random() << std::endl;
	}
	return 0;
	*/
	cout.precision(9);
	while(1)
	{
		x = get_random();
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
