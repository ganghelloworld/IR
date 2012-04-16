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
	BST(){};
	BST(T* a, int length);
	Node<T>* tree_search(int);
	void in_order() const;
	Node<T>* minimum(){ minimum(root); }
	Node<T>* maximum(){ maximum(root); }
	Node<T>* successor();
	Node<T>* predecessor();
private:
	void insert(T z);
	Node<T>* tree_search(int, Node<T>*);
	Node<T>* iterative_tree_search(int);
	void in_order_tree_walk(Node<T> * node) const;
	Node<T>* minimum(Node<T>*);
	Node<T>* maximum(Node<T>*);
};
template <class T>
Node<T>* BST<T>::successor()
{
	
}
template <class T>
Node<T>* BST<T>::minimum(Node<T>* node)
{
	Node<T>* temp = node;
	while(node != 0)
	{
		temp = node;
		node = node->left;
	}
	return temp;
}
template <class T>
Node<T>* BST<T>::maximum(Node<T>* node)
{
	Node<T>* temp = node;
	while(node != 0)
	{
		temp = node;
		node = node->right;
	}
	return temp;
}
template <class T>
Node<T>* BST<T>::iterative_tree_search(int k)
{
	Node<T> * node = root;
	while(node != 0 && node->data != k)
	{
		if(k < node->data) node = node->left;
		else node = node->right;
	}
	return node;
}
template <class T>
Node<T>* BST<T>::tree_search(int k)
{
	return tree_search(k,  root);
	//return iterative_tree_search(k);
}
template <class T>
Node<T>* BST<T>::tree_search(int k, Node<T>* node)
{
	if(node == 0 || k == node->data) return node;
	else if(k < node->data) return tree_search(k, node->left);
	else return tree_search(k, node->right);
}

template <class T>
BST<T>::BST(T* a, int length): root(0)
{
	//std::cout << length << std::endl;
	for(int i = 0; i < length; i++)
	{
		insert(a[i]);
	}
}

template <class T>
void BST<T>::in_order() const
{
	in_order_tree_walk(root);
}

template <class T>
void BST<T>::in_order_tree_walk(Node<T> * node) const
{
	if(node == 0) return;
	in_order_tree_walk(node->left);
	std::cout << node->data << " ";
	in_order_tree_walk(node->right);
}

template <class T>
void BST<T>::insert(T z)
{
	//std::cout << "node z = " << z << std::endl;;
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
#endif //BST_H
