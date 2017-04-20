/* declearation of node class */
#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node
{
	friend class Tree;
private:
	Node *parent;
	Node *left;
	Node *mid;
	Node *right;
	int val1, val2;
	int type;
public:
	Node(int num1, int num2, int t)
	{
		parent = left = mid = right = NULL;
		val1 = num1;
		val2 = num2;
		type = t;
	}
};

#endif