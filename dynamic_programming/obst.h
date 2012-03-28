#ifndef OBST_H
#define OBST_H

class Obst
{
	float* p;
	float* q;
	float** e;
	float** w;
	int** root;
	int num;

	void construct_tree(int, int);
public:
	Obst(float*, float*, int);
	void calculate();
	float get_min_cost(){ return e[1][num-2];}
	void print_tree();
	~Obst();
};

#endif //OBST_H
