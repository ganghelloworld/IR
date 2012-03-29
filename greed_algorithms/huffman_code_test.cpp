#include "huffman_code.h"
#include <iostream>

using namespace std;
static const in NUM = 6;
int main()
{
	CharUnit cu[NUM] = {{'a', 45}, {'b', 13}, {'c', 12}, 
					   {'d', 16}, {'e', 9}, {'f', 5}};
	HuffmanCode hc(cu, NUM);
	hc.output_code();
}
