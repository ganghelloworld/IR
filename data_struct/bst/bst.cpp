#include "bst.h"
#include <iostream>

using namespace std;
/*
template <class T>
Node<T>::Node(T d, Node* p, Node* l, Node* r) : 
	data(d), parent(p), left(l), right(r)
{}
*/
/*
template <class T>
BST<T>::BST(T* a, int length): root(0)
{
	for(int i = 0; i < length; i++)
	{
		insert(a[i]);
	}
}
*/
/*
template <class T>
void BST<T>::insert(T z)
{
	if(root == 0)
	{
		root = new Node<T>(z);
	}
	Node<T>* target = root;
	Node<T>* temp;
	while(target != 0)
	{
		temp = target;
		if(z <= target->data)
		{
			target = target->left;
		}
		else
		{
			target = target->right;
		}
	}
	target = new Node<T>(z, temp);
	if(z <= temp->data) temp->left = target;
	else temp->right = target;
}
*/
/*
template <class T>
void BST<T>::in_order()
{
	in_order_tree_walk(root);
}

template <class T>
void BST<T>::in_order_tree_walk(Node<T>* node)
{
	if(node == 0) return;
	in_order_tree_walk(node->left);
	cout << node->data << " ";
	in_order_tree_walk(node->right);
}
*/
