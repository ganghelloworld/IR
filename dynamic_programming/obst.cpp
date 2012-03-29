#include "obst.h"
#include "../include/constant.h"
#include "../include/utility.h"
#include <iostream>
#include <cstring>

using namespace std;

Obst::Obst(float* pp, float* qq, int n):
	p(0), q(0), num(n+1)
{
	p = new float[num];
	memcpy(p+1, pp, sizeof(float) * (num-2));
	q = new float[num];
	memcpy(q, qq, sizeof(float) * (num-1));

	e = new float*[num];
	w = new float*[num];
	root = new int*[num];

	for(int i = 0; i < num; i++)
	{
		e[i] = new float[num];
		memset(e[i], 0, sizeof(float)*num);
		w[i] = new float[num];
		memset(w[i], 0, sizeof(float)*num);
		root[i] = new int[num];
		memset(w[i], 0, sizeof(int)*num);
	}
}
void Obst::print_tree()
{
	cout << "k" << root[1][num-2] << " is root" << endl;
	construct_tree(1, num-2);
}
void Obst::construct_tree(int i, int j)
{
	if(i == j) 
	{
		cout << "d" << i-1 << " is left child of k" << i << endl;
		cout << "d" << i << " is right child of k" << i << endl;
		return;
	}
	if(i == root[i][j])
	{
		cout << "d" << i-1 << " is left child of k" << i << endl;
		return;
	}
	cout << "k" << root[i][root[i][j]-1] << " is left child of k" << root[i][j] << endl;;
	construct_tree(i, root[i][j]-1);
	if(j == root[i][j])
	{
		cout << "d" << j << " is right child of k" << j << endl;
		return;
	}
	cout << "k" << root[root[i][j]+1][j] << " is right child of k" << root[i][j] << endl;;
	construct_tree(root[i][j]+1, j);
}
void Obst::calculate()
{
	for(int i = 1; i < num; i++)
	{
		w[i][i-1] = q[i-1];
		e[i][i-1] = q[i-1];
	}
	float temp;
	int j;
	for(int l = 1; l < num - 1; l++)
	{
		for(int i = 1; i < num - l; i++)
		{
			j = i + l - 1;
			e[i][j] = MAX_INT;
			w[i][j] =  w[i][j-1] + p[j] + q[j];
			for(int k = i; k <= j; k++)
			{
				temp = e[i][k-1] + e[k+1][j] + w[i][j];
				if(e[i][j] > temp)
				{
					e[i][j] = temp;
					root[i][j] = k;
				}
			}
		}
	}
	display_matrix(e, num, num);
	cout << "========" << endl;
	display_matrix(w, num, num);
	cout << "========" << endl;
	display_matrix(root, num, num);
	cout << "========" << endl;
}
Obst::~Obst()
{
	delete []p;
	delete []q;

	for(int i = 0; i < num; i++)
	{
		delete []e[i];
		delete []w[i];
		delete []root[i];
	}
	delete []e;
	delete []w;
	delete []root;
}
