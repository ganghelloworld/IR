#include "activity_selection.h"
#include <iostream>

using namespace std;

static const int NUM = 11;

int main()
{
	//Activity a[] = {{1, 4}};
	Activity a[] = {{1, 4},{3, 5}, {0, 6}, {5, 7}, {3, 9}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 14}, {12, 16}};	

	ActSel as(a, NUM);
	as.calculate();
	as.output();
}
