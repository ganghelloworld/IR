#ifndef BST_INT_H
#define BST_INT_H
#include "bst.h"
class BSTInt:public BST<int>
{
public:
	BSTInt(int *a, int l): BST<int>(a, l){};
};

#endif //BST_INT_H
