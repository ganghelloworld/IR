#ifndef BST_H
#define BST_H
#include <iostream>
template <class T>
class Node
{
public:
	Node(){};
	Node(T d, Node* p = 0, Node* l = 0, Node* r = 0):
		data(d), parent(p), left(l), right(r){};
	T data;
	Node* parent;
	Node* left;
	Node* right;
};

template <class T>
class BST
{
private:
	Node<T>* root;
public:
	BST(){ std::cout << "b";};
	BST(T* a, int length): root(0)
	{
		std::cout << length << std::endl;
		for(int i = 0; i < length; i++)
		{
			std::cout << a[i] << std::endl;
			insert(a[i]);
		}
	}
	void in_order()
	{
		in_order_tree_walk(root);
	}
	void in_order_tree_walk(Node<T> * node)
	{
		if(node == 0) return;
		in_order_tree_walk(node->left);
		std::cout << node->data << " ";
		in_order_tree_walk(node->right);
	}
private:
	void insert(T z)
	{
		std::cout << "node z = " << z << std::endl;;
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
};
#endif //BST_H
