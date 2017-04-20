/* declearation of node class */
#ifndef NODE_H
#define NODE_H

class Node
{
	friend class RBT;
public:
	Node(int, bool);
private:
	int val;
	bool red;
	Node *left;
	Node *right;
};

#endif