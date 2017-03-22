/* decleration of class tree */
#ifndef TREE_H
#define TREE_H

#include"Node.h"

class BSTree
{
public:
	BSTree(Node *);
	void insert(int);
	int size();
	int rank(int);
	int select(int);
private:
	Node *root;
	Node * insert(Node *, int);
	int size(Node *);
	int rank(int, Node *);
	int select(int, Node *);
};

#endif