#include "bst.h"
#include <iostream>
#include <string>

using namespace std;

static const int NUM = 11;

template <class T>
void print_node(Node<T>* node, string msg)
{
	if(node != 0) cout << node->data << endl;
	else cout << msg << endl;
}
int main()
{
	int a[] = {15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
	BST<int> b(a, NUM);
	b.in_order();
	cout << endl;

	int key = 7;
	Node<int>* node = b.tree_search(key);
	print_node(node, "key is not in bst");

	node = b.minimum();
	print_node(node, "min not found");

	node = b.maximum();
	print_node(node, "max not found");
}
