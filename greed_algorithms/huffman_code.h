#ifndef HUFFMAN_CODE_H
#define HUFFMAN_CODE_H

#include <string>

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
	CharUnit* cu;
	int num;

	void coding();
public:
	HuffmanCode(){};
	HuffmanCode(CharUnit*, int);	
	void output_code() const;
	~HuffmanCode();
};

#endif //HUFFMAN_CODE_H
