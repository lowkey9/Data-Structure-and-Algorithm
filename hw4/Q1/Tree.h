/* declearation of tree class */
#ifndef TREE_H
#define TREE_H
#include "Node.h"

class Tree
{
private:
	Node *root;
	Node * insert(int, Node *);
	void display(Node *, int);
public:
	Tree();
	void insert(int);
	Node * replace(int, Node *);
	Node * split(int, Node *);
	Node * split2(int, Node *);
	Node * split3(int, Node *, Node *);
	void display();
	int findmedian(int, Node *);
	Node * search(int, Node *);
};

#endif
