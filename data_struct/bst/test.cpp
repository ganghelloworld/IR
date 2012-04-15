#include "bst.h"
#include <iostream>

using namespace std;

static const int NUM = 11;
int main()
{
	int a[] = {15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
	cout << "a" << endl;
	myBST<int> b(a, NUM);
	b.in_order();
	cout << endl;
}
