/* member function of node class */
#include <iostream>
#include "Node.h"

Node::Node(int v, bool c)
{
	val = v;
	red = c;
	left = right = NULL;
}