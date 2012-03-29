#include "huffman_code.h"
#include <iostream>
#include <string>

using namespace std;

HuffmanCode::HuffmanCode(CharUnit* c, int n):
	cu(0), num(n)
{
	cu = new CharUnit[num];
	for(int i = 0; i < num; i++)
	{
		cu[i] = c[i];
	}
}
void HuffmanCode::coding()
{
	bool tag = new bool[num];
	for(int = 0; i < num; i++) tag[i] = false;
}
void HuffmanCode::output_code() const
{
	for(int i = 0; i < num; i++)
	{
		cout << cu[i].ch << "\t" << cu[i].fre
			<< "\t" << cu[i].code << endl;
	}
}
HuffmanCode::~HuffmanCode()
{
	delete []cu;
}
