#include "sort.h"
#include <iostream>

using namespace std;
#define NUM 10

void display_array(int [], int);

int main()
{
	int a[] = {3, 5, 4, 19, 15, 7, 6, 9, 2, 17};
	Sort sort;

	display_array(a, NUM);

	sort.heap_sort(a, NUM);

	display_array(a, NUM);
	return 0;
}

void display_array(int a[], int length)
{
	for(int i = 0; i < length; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}
