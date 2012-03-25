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

	memset(p, 0, len);
	memset(r, 0, len);
	memset(r, 0, len);
	for(int i = 1; i < len; i++)
	{
		p[i] = q[i-1];
	}
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
	bottom_up();
	display_array(p+1, len-1);
	display_array(r+1, len-1);
	display_array(s+1, len-1);
}

void RodCut::bottom_up()
{
	int q;
	for(int i = 1; i < len; i++)
	{
		q = p[i];
		s[i] = i;
		for(int j = 1; j < i; j++)
		{
			if(q < (r[j] + r[i - j]))
			{
				q = r[j] + r[i - j];
				s[i] = j;
			}
		}
		r[i] = q;
	}
}
