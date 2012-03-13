#include "sort.h"
#include "utility.h"
#include <iostream>
#include <cstdio>

using namespace std;
bool debug = false;
void Sort::count_sort(int a[], int length)
{
	int max = a[0];
	for(int i = 1; i < length; i++)
	{
		if(max < a[i])
		{
			max = a[i];
		}
	}
	max ++;
	if(debug) cout << "max " << max << endl;
	int * b = new int[max];
	for(int i = 0; i < max; i++) b[i] = 0;
	
	if(debug) cout << "b is : " << endl;
	for(int i = 0; i < length; i++) b[a[i]] ++;
	if(debug) display_array(b, max);

	if(debug) cout << "add b is : " << endl;
	for(int i = 1; i < max; i++) b[i] += b[i-1];
	if(debug) display_array(b, max);
	
	int * c = new int[length];
	if(debug) cout << "c is : " << endl;
	for(int i = length - 1; i >= 0; i--)
	{
		c[b[a[i]]-1] = a[i];
		b[a[i]]--;
	}
	if(debug) display_array(c, length);
	for(int i = 0; i < length; i++)
	{
		a[i] = c[i];
	}
	delete []b;
	delete []c;
}
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
