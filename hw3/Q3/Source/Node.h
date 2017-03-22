/* decleration of class node */
#ifndef NODE_H
#define NODE_H

class Node
{
	friend class BSTree;
public:
	Node(int);
private:
	int val;
	int count;
	Node *left;
	Node *right;
};

#endif