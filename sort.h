#define left_child(i) (2 * i + 1)
#define right_child(i) (2 * (i + 1))

struct Sort
{
	void heap_sort(int [], int);
	void quick_sort(int [], int);
	void count_sort(int [], int);

	void max_heapify(int [], int, int);
	void build_max_heap(int [], int);

	void quick_sort_e(int [], int, int);
	int quick_sort_partition(int [], int, int);
};
