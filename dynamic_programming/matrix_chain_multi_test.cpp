#include "matrix_chain_multi.h"
#include "../constant.h"
#include <iostream>

using namespace std;

static const int size = 7;

int main()
{
	int A[] = {30, 35, 15, 5, 10, 20, 25};
	MatrixChainMulti mcm(A, size);
	mcm.calculate();
	cout << "minimum calculate = " << mcm.get_minimum() << endl;
	mcm.parenthesize();
	return 0;
}
