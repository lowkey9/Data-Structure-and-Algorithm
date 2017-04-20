/* declearation of RedBlackTree class */
#ifndef RBT_H
#define RBT_H
#include <iostream>
#include "Node.h"

class RBT
{
private:
	Node *root = NULL;
	Node * put(Node *, Node *);
	void display(Node *, int);
	void show(Node *);
	int compares = 0;
	int rotations = 0;
	int splits = 0;
public:
	bool isRed(Node *);
	Node * rotateLeft(Node *);
	Node * rotateRight(Node *);
	void flipColor(Node *);
	void put(Node *);
	void display();
	void show();
	int getRotations();
	int getSplits();
	int getCompares();
};

#endif
