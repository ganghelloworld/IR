#include "huffman_code.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

HuffmanCode::HuffmanCode(CharUnit* c, int n):
	tree(0), num(n)
{
	tree = new TreeNode<CharUnit>[num];
	for(int i = 0; i < num; i++)
	{
		tree[i].set_data(c[i]);
	}
	size = num;
	coding();
}
void HuffmanCode::coding()
{
	TreeNode<CharUnit> temp;
	while(size > 1)
	{
		int left = find_min_index();
		size--;
		temp = tree[left];
		tree[left] = tree[size];
		tree[size] = temp;
		int right = find_min_index();

		TreeNode<CharUnit>* root = new TreeNode<CharUnit>;
		non_leaf.push_back(root);
		*root = tree[right];
		tree[right].data.fre += tree[size].data.fre;
		tree[right].set_child(&tree[size], root);
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
void HuffmanCode::output_code()
{
	cout << tree[0].data.fre << endl;
	construct_code(tree[0]);
}
void HuffmanCode::construct_code(TreeNode<CharUnit>& tn)
{
	if(tn.left == 0 && tn.right == 0)
	{
		cout << tn.data.ch << "\t" << tn.data.fre <<
				"\t" << tn.data.code << endl;
		return;
	}
	tn.left->data.code.append(tn.data.code);
	tn.left->data.code.push_back('0');
	construct_code(*(tn.left));
	tn.right->data.code.append(tn.data.code);
	tn.right->data.code.push_back('1');
	construct_code(*(tn.right));
}
HuffmanCode::~HuffmanCode()
{
	delete []tree;
	for(int i = 0; i < non_leaf.size(); i++)
	{
		delete non_leaf[i];
	}
	non_leaf.clear();
}
