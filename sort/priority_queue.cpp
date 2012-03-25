#include "priority_queue.h"
#include "../utility.h"
#include "../constant.h"
#include <iostream>
#include <cassert>

using namespace std;

void Priority_queue::insert(int x)
{
	int * q = new int[size + 1];
	for(int i = 0; i < size; i++)
	{
		q[i] = p[i];
	}
	q[size] = MIN_INT;
	size++;
	if(size > 1)
	{
		delete []p;
	}
	p = q;
	assert(p);
	increase(size-1, x);
}
int Priority_queue::get_max_num()
{
	return *p;	
}
int Priority_queue::extract_max()
{
	int temp = p[0];
	p[0] = p[size - 1];
	size--;
	max_heapify(0);
	return temp;
}
void Priority_queue::max_heapify(int i)
{
	if(i >= size - 1) return;
	int l = left_child(i);
	int r = right_child(i);
	int large = i;
	if(l < size && p[l] > p[large]) large = l;

	if(r < size && p[r] > p[large]) large = r;

	if(large == i) return;

	int temp = p[large];
	p[large] = p[i];
	p[i] = temp;
	max_heapify(large);
}
void Priority_queue::increase(int index, int key)
{
	if(key <= p[index]) return;

	p[index] = key;
	int temp;

	for(int i = index; i > 0 && parent(i) >= 0; i = parent(i))
	{
		//cout << "i = " << i << " || parent = " << parent(i) << endl;
		if(p[i] > p[parent(i)])
		{
			temp = p[parent(i)];
			p[parent(i)] = p[i];
			p[i] = temp;
		}
	}
}
