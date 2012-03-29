#include "activity_selection.h"
#include <iostream>

using namespace std;

ActSel::ActSel(Activity* a, int n) :
	act(0), num(n)
{
	act = new Activity[num];
	selected = new bool[num];
	for(int i = 0; i < num; i ++)
	{
		act[i] = a[i];
		selected[i] = false;
	}
}

void ActSel::calculate()
{
	selected[0] = true;
	int current = act[0].end;
	int index = 1;
	while(index < num)
	{
		if(act[index].start >= current)
		{
			selected[index] = true;
			current = act[index].end;
		}
		index++;
	}
}

void ActSel::output() const
{
	for(int i = 0; i < num; i++)
	{
		if(selected[i])
		{
			cout << i << "\t" << act[i].start << "\t"
				<< act[i].end << endl;
		}
	}
}

ActSel::~ActSel()
{
	delete []act;
}
