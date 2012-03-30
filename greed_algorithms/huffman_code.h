#ifndef HUFFMAN_CODE_H
#define HUFFMAN_CODE_H

#include <string>
template <class T>
class TreeNode
{
	TreeNode* left;
	TreeNode* right;
	T data;
public:
	TreeNode() : left(0), right(0){};
	TreeNode(T t) : left(0), right(0), data(t){};
	TreeNode& operator=(const TreeNode& tn)
	{
		left = tn.left;
		right = tn.right;
		data = tn.data;
	}
	void set_child(TreeNode* l, TreeNode* r)
	{
		left = l;
		right = r;
		data.fre = l.data.fre + r.data.fre;
	}
	friend class HuffmanCode;
	friend class CharUnit;
};
class CharUnit
{
	char ch;
	int fre;
	string code;
public:
	CharUnit(){};
	CharUnit(char c, int f) : ch(c), fre(f), code(0){};
	CharUnit(char c, int f, string co) :
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
};

class HuffmanCode
{
	TreeNode<CharUnit>* tree;
	int num;
	int size;

	void coding();
	int find_min_index();
public:
	HuffmanCode(){};
	HuffmanCode(CharUnit*, int);	
	void output_code() const;
	~HuffmanCode();
};

#endif //HUFFMAN_CODE_H
