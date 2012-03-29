#ifndef ACTIVITY_SELECTION_H
#define ACTIVITY_SELECTION_H

//class ActSel;
class Activity
{
	int start;
	int end;
public:
	Activity(){};
	Activity(int s, int e): start(s), end(e){};
	Activity(const Activity& a)
	{
		start = a.start;
		end = a.end;
	}
	Activity& operator=(const Activity& a)
	{
		start = a.start;
		end = a.end;
		return *this;
	}
	friend class ActSel;
};

class ActSel
{
	Activity* act;
	bool *selected;
	int num;
public:
	ActSel(Activity*, int);
	void calculate();
	void output() const;
	~ActSel();
};

#endif //ACTIVITY_SELECTION_H
