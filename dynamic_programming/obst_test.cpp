#include "obst.h"
#include <iostream>

using namespace std;

const int SIZE = 6;

int main()
{
	float p[] = {0.15, 0.1, 0.05, 0.1, 0.2};
	float q[] = {0.05, 0.1, 0.05, 0.05, 0.05, 0.1};
	
	Obst o(p, q, SIZE);

	o.calculate();

	cout << "min cost = " << o.get_min_cost() << endl;

	//o.print_tree();
}
