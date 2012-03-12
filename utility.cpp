#include "utility.h"

using namespace std;

void display_array(int a[], int length)
{
	for(int i = 0; i < length; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}
