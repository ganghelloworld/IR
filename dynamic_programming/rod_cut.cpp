#include "rod_cut.h"
#include "../constant.h"
#include "../utility.h"
#include <iostream>
#include <cstring>

using namespace std;

RodCut::RodCut(int *q, int size) : 
	p(0), r(0), s(0), len(size + 1)
{
	p = new int[len];
	r = new int[len];
	s = new int[len];

	memset(p, 0, sizeof(int) * len);
	memset(r, 0, sizeof(int) * len);
	memset(r, 0, sizeof(int) * len);
	/*
	for(int i = 1; i < len; i++)
	{
		p[i] = q[i-1];
	}
	*/
	memcpy(p+1, q, sizeof(int) * (len-1));
}

void RodCut::cut(int n) const
{
	if(n <= 0) return;
	while(n > 0)
	{
		cout << s[n] << " ";
		n = n - s[n];
	}
	cout << endl;
}

void RodCut::calculate()
{
	up_bottom();
	display_array(p+1, len-1);
	display_array(r+1, len-1);
	display_array(s+1, len-1);
}
void RodCut::up_bottom()
{
	r[0] = 0;
	for(int i = 1; i < len; i++)
	{
		r[i] = MIN_INT;
	}
	up_bottom_lookup(len-1);
}
int RodCut::up_bottom_lookup(int n)
{
	if(r[n] > MIN_INT) return r[n];
	int q = MIN_INT;
	int temp;
	for(int i = 1; i <= n; i++)
	{
		temp = p[i] + up_bottom_lookup(n-i);
		if(q < temp)
		{
			q = temp;
			s[n] = i;
		}
	}
	r[n] = q;
	return r[n];
}
void RodCut::bottom_up()
{
	int q;
	for(int i = 1; i < len; i++)
	{
		q = MIN_INT;
		for(int j = 1; j <= i; j++)
		{
			if(q < (p[j] + r[i - j]))
			{
				q = p[j] + r[i - j];
				s[i] = j;
			}
		}
		r[i] = q;
	}
}
