#include "matrix_chain_multi.h"
#include "../include/utility.h"
#include "../include/constant.h"
#include <cstring>
#include <iostream>

using namespace std;

MatrixChainMulti::MatrixChainMulti(int *q, int l)
	: p(0), num(l)
{
	p = new int[num];
	m = new int*[num];
	s = new int*[num];
	for(int i = 0; i < num; i++)
	{
		p[i] = q[i];
		m[i] = new int[num];
		s[i] = new int[num];
		memset(m[i], 0, sizeof(int) * num);
		memset(s[i], 0, sizeof(int) * num);
	}
}

int MatrixChainMulti::get_minimum()
{
	return m[1][num-1];
}
void MatrixChainMulti::calculate()
{
	up_bottom();
	cout << "m :" << endl;
	display_matrix(m, num, num);
	cout << "s :" << endl;
	display_matrix(s, num, num);
}
int MatrixChainMulti::up_bottom(int l, int r)
{
	if(l == r)
	{
		m[l][r] = 0;
		s[l][r] = l;
		return 0;
	}
	int left, right, k, q = MAX_INT;
	for(k = l; k < r; k++)
	{
		left = (m[l][k] < MAX_INT) ? m[l][k] : up_bottom(l, k);
		right = (m[k+1][r] < MAX_INT) ? m[k+1][r] : up_bottom(k+1, r);
		if(q > (left + right + p[l-1] * p[k] * p[r]))
		{
			q = left + right + p[l-1] * p[k] * p[r];
			s[l][r] = k;
		}
	}
	m[l][r] = q;
	return q;
}
void MatrixChainMulti::up_bottom()
{
	for(int i = 0; i < num; i++)
	{
		for(int j = 0; j < num; j++)
		{
			m[i][j] = MAX_INT;
		}
	}
	up_bottom(1, num-1);
}
void MatrixChainMulti::bottom_up()
{
	int i, j, k, l;
	int q = MAX_INT, temp;
	for(i = 1; i < num; i++)
		m[i][i] = 0;
	
	for(l = 2; l < num; l++)
	{
		for(i = 1; i < num - l + 1; i++)
		{
			j = i + l - 1;
			q = MAX_INT;
			for(k = i; k < j; k++)
			{
				temp = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(q > temp)
				{
					q = temp;
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}
void MatrixChainMulti::parenthesize()
{
	parenthesize(1, num-1);
	cout << endl;
}
void MatrixChainMulti::parenthesize(int l, int r)
{
	if(l == r)
	{
		cout << "A" << l;
		return;
	}
	cout << "(";
	parenthesize(l, s[l][r]);
	cout << " * ";
	parenthesize(s[l][r]+1, r);
	cout << ")";
}
MatrixChainMulti::~MatrixChainMulti()
{
	delete []p;
	for(int i = 0; i < num; i++)
	{
		delete []m[i];
		delete []s[i];
	}
	delete []m;
	delete []s;
}
