#include "huffman_code.h"
#include "../include/constant.h"
#include <iostream>
#include <string>

using namespace std;

HuffmanCode::HuffmanCode(CharUnit* c, int n):
	cu(0), num(n)
{
	tree = new TreeNode<CharUnit>[num];
	for(int i = 0; i < num; i++)
	{
		tree[i] = TreeNode<CharUnit>(c[i]);
	}
	size = num;
	coding();
}
void HuffmanCode::coding()
{
	while(size > 1)
	{
		TreeNode<CharUnit>* root = new TreeNode<CharUnit*>;
		TreeNode<CharUnit> temp;

		int left = find_min_index();
		size--;
		temp = tree[left];
		tree[left] = tree[size];
		tree[size] = temp_node;
		int right = find_min_index();

		temp_node = tree[left];
		root.set_child(&temp_node, &tree[size]);
	}
}
int HuffmanCode::find_min_index()
{
	int temp = tree[0].data.fre;
	int index = 0;
	for(int i = 1; i < size; i++)
	{
		if(tree[i].data.fre < temp)
		{
			temp = tree[i].data.fre;	
			index = i;
		}
	}
	return index;
}
void HuffmanCode::output_code() const
{
	for(int i = 0; i < num; i++)
	{
		cout << cu[i].ch << "\t" << cu[i].fre
			<< "\t" << cu[i].code << endl;
	}
}
HuffmanCode::~HuffmanCode()
{
	delete []cu;
}
