#include "sort.h"
#include "priority_queue.h"
#include <iostream>

#define NUM 10
using namespace std;

void display_array(int [], int);

int main()
{
	int a[] = {3, 5, 4, 19, 15, 7, 6, 9, 2, 17};
	/*
	Sort s;
	display_array(a, NUM);
	s.heap_sort(a, NUM);
	display_array(a, NUM);
	*/
	Priority_queue pq;
	for(int i = 0;i < NUM; i++)
	{
		pq.insert(a[i]);
	}
	cout << pq.get_max_num() << "\n";
	pq.increase(3, 100);
	for(int i = 0; i < NUM; i++)
	{
		cout << pq.extract_max() << "\t";
	}
	cout << endl;
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
