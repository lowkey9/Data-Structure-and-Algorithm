/* member function of class tree */
#include<iostream>
#include<iomanip>
#include"Node.h"
#include"Tree.h"

using namespace std;

BSTree::BSTree(Node *nullPtr)
{
	root = nullPtr;
}

void BSTree::insert(int num)
{
	root = insert(root, num);
}

Node * BSTree::insert(Node *curNode, int num)
{
	if (curNode == NULL) {
		return new Node(num);
	}
	else {
		if (num < curNode->val) {
			curNode->left = insert(curNode->left, num);
		}
		else if (num > curNode->val) {
			curNode->right = insert(curNode->right, num);
		}
		else
			curNode->val = num;
		curNode->count = size(curNode->left) + size(curNode->left) + 1;
		return curNode;
	}
}

int BSTree::size()
{
	return size(root);
}

int BSTree::size(Node *curNode)
{
	if (curNode == NULL)
		return 0;
	return curNode->count;
}

int BSTree::rank(int num)
{
	return rank(num, root);
}

int BSTree::rank(int num, Node *curNode)
{
	if (curNode == NULL)
		return 0;
	else {
		if (num < curNode->val)
			return rank(num, curNode->left);
		else if (num > curNode->val)
			return 1 + size(curNode->left) + rank(num, curNode->right);
		else
			return size(curNode);
	}
}

int BSTree::select(int num)
{
	return select(num, root);
}

int BSTree::select(int num, Node *curNode)
{
	if (curNode == NULL)
		return -1;
	else {
		if (size(curNode->left) > num)
			return select(num, curNode->left);
		else if (size(curNode->left) < num) {
			int tmp = size(curNode->left);
			return select(num - tmp - 1, curNode->right);
		}
		else
			return curNode->val;
	}
}