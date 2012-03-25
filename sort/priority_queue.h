#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

class Priority_queue
{
	int *p;
	int size;
	void max_heapify(int);
public:
	Priority_queue() : p(0), size(0){}
	void insert(int);
	int get_max_num();
	int extract_max();
	void increase(int, int);
	~Priority_queue()
	{
		delete []p;
		size = 0;
	}
};

extern const int MIN_INT;
#endif //PRIORITY_QUEUE_H
