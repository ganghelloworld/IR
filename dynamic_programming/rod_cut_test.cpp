#include "rod_cut.h"
#include <iostream>

using namespace std;

const int NUM = 10;

int main()
{
	int a[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	RodCut rc(a+1, NUM);

	rc.calculate();
	
	cout << "max price = " << rc.get_max_price(NUM) << endl;
	rc.cut(7);
}
