#include "bst.h"
#include <iostream>
#include <string>

using namespace std;

template <class T>
void print_node(Node<T>* node, string msg)
{
	if(node != 0) cout << node->data << endl;
	else cout << msg << endl;
}
int main()
{
	int a[] = {15, 6, 18, 3, 8, 17, 20, 4, 13, 9};
	BST<int> b(a, (sizeof a) / (sizeof a[0]));
	b.in_order();
	cout << endl;
	/*
	b.pre_order();
	cout << endl;
	b.post_order();
	cout << endl;
	*/

	int key = 6;
	Node<int>* node = b.tree_search(key);
	print_node(node, "key is not in bst");

	b.delete_node(node);
	b.in_order();
	cout << endl;

	/*
	key = 18;
	node = b.tree_search(key);
	b.del_node(node);
	b.in_order();
	cout << endl;
	*/

	/*
	node = b.predecessor(node);
	print_node(node, "successor not found");

	node = b.maximum();
	print_node(node, "max not found");

	node = b.minimum();
	print_node(node, "min not found");
	*/

}
