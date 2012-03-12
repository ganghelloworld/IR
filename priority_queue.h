#define parent(i) ((i - 1) / 2)

#define left__(i) (2 * i + 1)
#define right__(i) (2 * (i + 1))


#define MIN_INT -9999

struct Priority_queue
{
	int *p;

	void insert(int);
	int get_max_num();
	int extract_max();
	void increase(int, int);
	void max_heapify(int);
};
