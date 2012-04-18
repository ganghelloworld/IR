#ifndef BST_H
#define BST_H
#include <iostream>
#include <stack>

template <class T>
class Node
{
public:
	Node(){};
	Node(T d, Node* p = 0, Node* l = 0, Node* r = 0):
		data(d), parent(p), left(l), right(r){};
	void print_info()
	{
		std::cout << data << "\t";
		if(left != 0)
			std::cout << "left " << left->data << "\t";
		else
			std::cout << "left X"<< "\t";
		if(right != 0)
			std::cout << "right " << right ->data << "\t";
		else
			std::cout << "right X"<< "\t";
		if(parent != 0)
			std::cout << "parent " << parent->data << "\t";
		else
			std::cout << "parent X"<< "\t";
		std::cout << std::endl;
	}
	~Node()
	{
		std::cout << "delete Node " << data << std::endl;
	};
public:
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
	Node<T>* tree_search(int) const;
	void in_order() const;
	void pre_order() const;
	void post_order() const;
	Node<T>* minimum() const { minimum(root); }
	Node<T>* maximum() const { maximum(root); }
	Node<T>* successor(Node<T>* node) const;
	Node<T>* predecessor(Node<T>* node) const;
	Node<T>* insert(T z);
	void del_node(Node<T>* node);
private:
	Node<T>* tree_search(int, Node<T>*) const;
	Node<T>* iterative_tree_search(int) const;
	void in_order_tree_walk(Node<T>* node) const;
	void pre_order_tree_walk(Node<T>* node) const;
	void post_order_tree_walk(Node<T>* node) const;
	Node<T>* minimum(Node<T>*) const;
	Node<T>* maximum(Node<T>*) const;
	void transplant(Node<T>* u, Node<T>* v);
};
template <class T>
void BST<T>::transplant(Node<T>* u, Node<T>* v)
{
	Node<T>* temp = new Node<T>;
	temp->parent = u->parent;
	temp->left = u->left;
	temp->right = u->right;

	exchange(u, v);
	exchange(v, temp);

	delete temp;
}
template <class T>
void BST<T>::del_node(Node<T>* node)
{
	if(node == 0) return;

	if(node->left == 0 && node->right == 0)
	{
		if(node->parent != 0)
		{
			if(node == node->parent->left)
			{
				std::cout << "0 0 left" << std::endl;
				node->parent->left = 0;
			}
			else
			{
				std::cout << "0 0 right" << std::endl;
				node->parent->right = 0;
			}
		}
		else
		{
			std::cout << "0 0 0" << std::endl;
			root = 0;
		}
	}
	else if(node->left == 0 && node->right != 0)
	{
		if(node->parent != 0)
			if(node->parent->left == node->right)
				node->parent->left = node->right;
			else node->parent->right = node->right;
		else root = node;
		node->right->parent = node->parent;
	}
	else if(node->left != 0 && node->right == 0)
	{
		if(node->parent != 0)
			if(node->parent->left == node->left)
				node->parent->left = node->left;
			else node->parent->right = node->left;
		else root = node;
		node->left->parent = node->parent;
	}
	else if(node->left != 0 & node->right != 0)
	{
		Node<T>* temp = successor(node);
		if(node->right == temp)
		{
			temp->left = node->left;
			node->left->parent = temp;
			temp->parent = node->parent;
			if(node->parent != 0)
			{
				if(node->parent->left == node)
					node->parent->left = temp;
				else
					node->parent->right = temp;
			}
			else root = temp;
		}
		else
		{
			temp->parent->left = temp->right;
			if(temp->right != 0)
				temp->right->parent = temp->parent;
			temp->parent = node->parent;
			if(node->parent != 0)
			{
				if(node->parent->left == node)
					node->parent->left = temp;
				else
					node->parent->right = temp;
			}
			else root = temp;
			temp->left = node->left;
			temp->right = node->right;
			temp->left->parent = temp;
			temp->right->parent = temp;
		}
	}
	else
	{
		std::cout << "error, node is not exist" << std::endl;
	}
	delete node;
}
template <class T>
Node<T>* BST<T>::successor(Node<T>* node) const
{
	if(node == 0) return node;
	if(node->right != 0) return minimum(node->right);
	else
	{
		Node<T>* temp = node->parent;
		while(temp != 0 && node == temp->right)
		{
			node = temp;
			temp = node->parent;
		}
		return temp;
	}
}

template <class T>
Node<T>* BST<T>::predecessor(Node<T>* node) const
{
	if(node == 0) return node;
	else if(node->left != 0) return maximum(node->left);
	else
	{
		Node<T>* temp = node->parent;
		while(temp != 0 && node == temp->left)
		{
			node = temp;
			temp = node->parent;
		}
		return temp;
		
	}
}

template <class T>
Node<T>* BST<T>::minimum(Node<T>* node) const
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
Node<T>* BST<T>::maximum(Node<T>* node) const
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
Node<T>* BST<T>::iterative_tree_search(int k) const
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
Node<T>* BST<T>::tree_search(int k) const
{
	return tree_search(k,  root);
	//return iterative_tree_search(k);
}
template <class T>
Node<T>* BST<T>::tree_search(int k, Node<T>* node) const
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
	return;
	std::stack<Node<T>*> s;
	Node<T>* temp;
	temp = root;
	while(1)
	{
		if(temp->left != 0)
		{
			s.push(temp);
			temp = temp->left;
			continue;
		}
		else if(temp->left == 0)
		{
			std::cout << temp->data << " ";
		}
		temp = s.top();
		std::cout << temp->data << " ";
		std::cout << "hello\n";
		if(temp->right != 0)
		{
			//s.push(temp);
			temp = temp->right;
		}
		else// if(s.size() == 0)
		{
			break;
		}
	}
}

template <class T>
void BST<T>::in_order_tree_walk(Node<T> * node) const
{
	if(node == 0) return;
	in_order_tree_walk(node->left);
	//std::cout << node->data << "\t";
	node->print_info();
	in_order_tree_walk(node->right);
}
template <class T>
void BST<T>::pre_order() const
{
	pre_order_tree_walk(root);
} 
template <class T>
void BST<T>::pre_order_tree_walk(Node<T> * node) const
{
	if(node == 0) return;
	std::cout << node->data << " ";
	pre_order_tree_walk(node->left);
	pre_order_tree_walk(node->right);
}

template <class T>
void BST<T>::post_order() const
{
	post_order_tree_walk(root);
}

template <class T>
void BST<T>::post_order_tree_walk(Node<T> * node) const
{
	if(node == 0) return;
	post_order_tree_walk(node->left);
	post_order_tree_walk(node->right);
	std::cout << node->data << " ";
}

template <class T>
Node<T>* BST<T>::insert(T z)
{
	if(root == 0)
	{
		root = new Node<T>(z);
		return root;
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

	return target;
}
#endif //BST_H
