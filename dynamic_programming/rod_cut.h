#ifndef ROD_CUT_H
#define ROD_CUT_H

class RodCut
{
	int *p;
	int len;
	int *r;
	int *s;

	void bottom_up();
public:
	RodCut(int *q, int size);
	void cut(int n) const;
	void calculate();
	int get_max_price(int n) const
	{
		if(n <= 0) return 0;
		return r[n];
	}
	~RodCut()
	{
		delete []p;
		delete []r;
		delete []s;
	}
};

#endif //ROD_CUT_H
