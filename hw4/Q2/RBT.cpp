/* member function of RedBlackTree */
#include <iostream>
#include <iomanip>
#include "Node.h"
#include "RBT.h"

using namespace std;

bool RBT::isRed(Node *curNode)
{
	if (curNode == NULL)
		return false;
	return curNode->red == true;
}

Node * RBT::rotateLeft(Node *curNode)
{
	if (isRed(curNode->right))
	{
		//rotate left
		Node *tmpNode = curNode->right;
		curNode->right = tmpNode->left;
		tmpNode->left = curNode;
		tmpNode->red = curNode->red;
		curNode->red = true;

		return tmpNode;
	}
}

Node * RBT::rotateRight(Node *curNode)
{
	if (isRed(curNode->left))
	{
		//rotate right
		Node *tmpNode = curNode->left;
		curNode->left = tmpNode->right;
		tmpNode->right = curNode;
		tmpNode->red = curNode->red;
		curNode->red = true;

		return tmpNode;
	}
}

void RBT::flipColor(Node *curNode)
{
	if (isRed(curNode->left) && isRed(curNode->right))
	{
		curNode->red = true;
		curNode->left->red = false;
		curNode->right->red = false;
	}
}

void RBT::put(Node *newNode)
{
	root = put(newNode, root);
}

Node * RBT::put(Node *newNode, Node *curNode)
{
	if (curNode == NULL)
		return newNode;
	
	//insert new node, no duplicate key
	else {
		if (newNode->val < curNode->val)
			curNode->left = put(newNode, curNode->left);
		else if (newNode->val > curNode->val)
			curNode->right = put(newNode, curNode->right);
		else
			curNode->val = newNode->val;
	}

	//update color in order to keep black balance
	if (isRed(curNode->right) && !isRed(curNode->left))
		curNode = rotateLeft(curNode);
	if (isRed(curNode->left) && isRed(curNode->left->left))
		curNode = rotateRight(curNode);
	if (isRed(curNode->left) && isRed(curNode->right))
		flipColor(curNode);

	return curNode;
}

void RBT::display()
{
	display(root, 4);
}

void RBT::display(Node *curNode, int n)
{
	if (curNode != NULL) {
		if (curNode->right) {
			display(curNode->right, n + 4);
		}
		if (n)
			cout << setw(n) << " ";
		if (curNode->right) {
			cout << " /\n" << setw(n) << " ";
		}
		std::cout << curNode->val << "\n ";
		if (curNode->left) {
			cout << setw(n) << " " << " \\\n";
			display(curNode->left, n + 4);
		}
	}
}

void RBT::show()
{
	show(root);
}

void RBT::show(Node *curNode)
{
	if (curNode != NULL)
	{
		show(curNode->left);
		cout << curNode->val << "\t";
		if (curNode->red)
			cout << "Red" << endl;
		else
			cout << "Black" << endl;
		show(curNode->right);
	}
}