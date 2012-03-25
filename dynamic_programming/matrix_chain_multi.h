#ifndef MATRIX_CHAIN_MULTI
#define MATRIX_CHAIN_MULTI

class MatrixChainMulti
{
	int* p;
	int num;
	int** m;
	int** s;
	void bottom_up();
	int up_bottom(int, int);
	void up_bottom();
	void parenthesize(int, int);
public:
	MatrixChainMulti(int* q, int l);
	void calculate();
	void parenthesize();
	int get_minimum();
	~MatrixChainMulti();
};

#endif //MATRIX_CHAIN_MULTI
