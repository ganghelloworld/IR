#ifndef SORT_H
#define SORT_H

#include "../utility.h"
#include "../constant.h"

class Sort
{
public:
	static void heap_sort(int [], int);
	static void quick_sort(int [], int);
	static void count_sort(int [], int);
	static void radix_sort(int [], int);

private:
	static void max_heapify(int [], int, int);
	static void build_max_heap(int [], int);

	static void quick_sort_e(int [], int, int);
	static int quick_sort_partition(int [], int, int);
};
extern const bool debug;
#endif //SORT_H
