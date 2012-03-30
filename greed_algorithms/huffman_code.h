#ifndef HUFFMAN_CODE_H
#define HUFFMAN_CODE_H

#include <string>
#include <iostream>
#include <vector>

template <class T>
class TreeNode
{
	TreeNode* left;
	TreeNode* right;
	T data;
public:
	TreeNode() : left(0), right(0){};
	//TreeNode(T t) : left(0), right(0), data(t){};
	void set_data(T& t)
	{
		data = t;
	}
	TreeNode& operator=(const TreeNode& tn)
	{
		if(this == &tn) return *this;
		left = tn.left;
		right = tn.right;
		data = tn.data;
		return *this;
	}
	void set_child(TreeNode* l, TreeNode* r)
	{
		left = l;
		right = r;
	}
	~TreeNode()
	{
		
		std::cout << "TreeNode::~TreeNode() " << data.ch  << std::endl;
	}
	friend class HuffmanCode;
	friend class CharUnit;
};
class CharUnit
{
	char ch;
	int fre;
	std::string code;
public:
	CharUnit(){};
	CharUnit(char c, int f) : ch(c), fre(f){};
	CharUnit(char c, int f, std::string co) :
		ch(c), fre(f), code(co){};
	CharUnit(const CharUnit& cu)
	{
		ch = cu.ch;
		fre = cu.fre;
		code = cu.code;
	}
	CharUnit& operator=(const CharUnit& cu)
	{
		ch = cu.ch;
		fre = cu.fre;
		code = cu.code;
	}
	friend class HuffmanCode;
	friend class TreeNode<CharUnit>;
};

class HuffmanCode
{
	TreeNode<CharUnit>* tree;
	int num;
	int size;
	std::vector<TreeNode<CharUnit>*> non_leaf;

	void coding();
	int find_min_index();
	void construct_code(TreeNode<CharUnit>&);
public:
	HuffmanCode(){};
	HuffmanCode(CharUnit*, int);	
	void output_code();
	~HuffmanCode();
};

#endif //HUFFMAN_CODE_H
