#include "sort.h"
#include <iostream>

using namespace std;

void Sort::quick_sort(int a[], int length)
{
	quick_sort_e(a, 0, length-1);
}
void Sort::quick_sort_e(int a[], int l, int r)
{
	if(l >= r) return;

	int p = quick_sort_partition(a, l, r);
	quick_sort_e(a, l, p-1);
	quick_sort_e(a, p+1, r);
}
int Sort::quick_sort_partition(int a[], int l, int r)
{
	int temp;
	int i = l-1;
	for(int j = l; j < r; j++)
	{
		if(a[j] < a[r])
		{
			temp = a[j];
			a[j] = a[i+1];
			a[i+1] = temp;
			i++;
		}
	}
	temp = a[r];
	a[r] = a[i+1];
	a[i+1] = temp;
	return i+1;
}
void Sort::heap_sort(int a[], int length)
{
    int i = length, temp;
	build_max_heap(a, length);
	for(i = length - 1; i >= 0; i--)
	{
		temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		max_heapify(a, 0, i);
	}
}

void Sort::max_heapify(int a[], int i, int length)
{
    int left = left_child(i);
    int right = right_child(i);
    int large = i, temp;

    if(i >= length) return; 
    if(left < length && a[i] < a[left]) large = left; 

    if(right < length && a[large] < a[right]) large = right;
    if(large == i) return;
    else if(large == left)
    {
        temp = a[left];
        a[left] = a[i];
        a[i] = temp;
        max_heapify(a, left, length);
    }
    else
    {
        temp = a[right];
        a[right] = a[i];
        a[i] = temp;
        max_heapify(a, right, length);
    }	
}

void Sort::build_max_heap(int a[], int length)
{
    int start = length / 2, i; 
    for(i = start; i >= 0; i--) 
    {
        max_heapify(a, i, length);
    }
}
