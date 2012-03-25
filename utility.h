#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>

inline void display_array(int a[], int length)
{
	for(int i = 0; i < length; i++)
	{
		std::cout << a[i] << "\t";
	}
	std::cout << std::endl;
}

inline int get_num_by_index(int num, int index)
{
	int res = num % 10;
	while(index)
	{
		num /= 10;
		res = num % 10;
		index --;
	}
}

inline int left_child(int i){ return 2*i + 1;}
inline int right_child(int i){ return 2*(i + 1);}
inline int parent(int i){ return (i - 1)/2;}

#endif //UTILITY_H
