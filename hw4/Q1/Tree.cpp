/* member functions of tree class */
#include <iostream>
#include <iomanip>
#include "Tree.h"

using namespace std;

Node *FinalParent = new Node(0, 0, 2);

Tree::Tree()
{
	root = NULL;
}

void Tree::insert(int num)
{
	root = insert(num, root);
}

Node * Tree::insert(int num, Node *curNode)
{
	/* insert to empty tree or empty position */
	if (curNode == NULL) {
		return new Node(num, 0, 2);
	}
	else {
		/* if current node is a 2 node */
		if (curNode->type == 2) {
			/* if this 2 node does not have children, replace it with a 3 node */
			if (curNode->left == NULL && curNode->right == NULL)
				curNode = replace(num, curNode);
			/* else compare num with value of curNode */
			else if (num < curNode->val1)
				curNode->left = insert(num, curNode->left);
			else if (num > curNode->val1)
				curNode->right = insert(num, curNode->right);
			else
				curNode->val1 = num;
		}

		/* if curNode is a 3 node */
		else if (curNode->type == 3) {
			// find where the num is to be inserted
			Node *tbiNode = search(num, curNode);
			
			/* if its parent is null */
			if (tbiNode->parent == NULL) {
				tbiNode = split(num, tbiNode);
				curNode = tbiNode;
			}
			/* if its parent is a 2 node */
			else if (tbiNode->parent->type == 2) {
				tbiNode = split2(num, tbiNode);
				curNode = tbiNode;
			}
			/* if its parent is a 3 node */
			else if(tbiNode->parent->type == 3) {
				/* if num equals to any number in curNode, return curNode */
				if (num == tbiNode->val1 || num == tbiNode->val2)
					return tbiNode;
				if (tbiNode->type == 2) {
					tbiNode = replace(num, tbiNode);
					curNode = tbiNode->parent;
				}
				else {
					tbiNode->parent->parent = split3(num, tbiNode->parent, NULL);		//这里有问题
					//curNode = split3(num, curNode->parent, NULL);		//return root-> to curNode
					curNode = tbiNode->parent->parent;
				}
			}
		}

		return curNode;
	}
}

Node * Tree::replace(int num, Node *curNode)
{
	/* if num equals to current val, return curNode */
	if (num == curNode->val1)
		return curNode;

	/* update curNode to 3 node */
	//update values
	if (num < curNode->val1) {
		curNode->val2 = curNode->val1;
		curNode->val1 = num;
	}
	else
		curNode->val2 = num;
	//update type
	curNode->type = 3;

	return curNode;
}

Node * Tree::split(int num, Node *curNode)		//for parent is null
{
	/* if num equals to any number in curNode, return curNode */
	if (num == curNode->val1 || num == curNode->val2)
		return curNode;

	/* find the median of three numbers */
	int median = findmedian(num, curNode);

	/* if the parent of curNode is null */
	if (curNode->parent == NULL) {
		Node *newParent = new Node(median, 0, 2);
		Node *newLeft = new Node(curNode->val1, 0, 2);
		newParent->left = newLeft;
		newLeft->parent = newParent;
		curNode->val1 = curNode->val2;
		curNode->val2 = 0;
		curNode->type = 2;
		newParent->right = curNode;
		curNode->parent = newParent;

		curNode = newParent;
	}

	return curNode;
}

Node * Tree::split2(int num, Node *curNode)
{
	/* if num equals to any number in curNode, return curNode */
	if (num == curNode->val1 || num == curNode->val2)
		return curNode;

	/* find the median of three numbers */
	int median = findmedian(num, curNode);

	/* if the parent of curNode is a 2 node */
	if (curNode->parent->type == 2) {
		if (median > curNode->parent->val1) {
			curNode->parent->val2 = median;						//update the parent to 3 node
			curNode->parent->type = 3;
			Node *newMid = new Node(curNode->val1, 0, 2);		//create new mid node and link it with parent
			newMid->parent = curNode->parent;
			curNode->parent->mid = newMid;
			curNode->val1 = curNode->val2;						//update curNode to 2 node
			curNode->val2 = 0;
			curNode->type = 2;
		}
		else {
			curNode->parent->val2 = curNode->parent->val1;		//update the parent to 3 node
			curNode->parent->val1 = median;
			curNode->parent->type = 3;
			Node *newMid = new Node(curNode->val2, 0, 2);		//create new mid node and link it with parent
			newMid->parent = curNode->parent;
			curNode->parent->mid = newMid;
			curNode->val2 = 0;									//update curNode to 2 node
			curNode->type = 2;
		}
	}

	return curNode;
}

Node * Tree::split3(int num, Node *curNode, Node *brother)
{
	int median = 0;
	int lift = 0;
	Node *newBrother = new Node(0, 0, 2);

	// if curNode is a 2 node (one of base cases)
	if (curNode->type == 2) {
		int sum = num + curNode->val1;
		curNode->val1 = (num < curNode->val1 ? num : curNode->val1);		//smaller number
		curNode->val2 = sum - curNode->val1;								//bigger number
		if (brother->val1 > curNode->val2) {
			curNode->mid = curNode->right;
			curNode->right = brother;
		}
		else
			curNode->mid = brother;
		brother->parent = curNode;

		return curNode;
	}

	else {
		// if num is to be inserted in left child
		if (num < curNode->val1) {
			lift = curNode->val1;

			newBrother->val1 = curNode->val2;
			newBrother->left = curNode->mid;
			newBrother->right = curNode->right;
			curNode->mid->parent = curNode->right->parent = newBrother;

			median = findmedian(num, curNode->left);
			curNode->val1 = median;
			curNode->val2 = 0;
			curNode->mid = curNode->left;
			curNode->left = new Node(curNode->mid->val1, 0, 2);
			curNode->right = new Node(curNode->mid->val2, 0, 2);
			curNode->left->parent = curNode->right->parent = curNode;
			//delete(curNode->mid);
			curNode->mid = NULL;
			curNode->type = 2;

			//curNode = split3(lift, curNode->parent, newBrother);
		}

		// if num is to be inserted in mid child
		else if (num < curNode->val2) {
			lift = median = findmedian(num, curNode->mid);

			newBrother->val1 = curNode->val2;
			Node *newLeft = new Node(curNode->mid->val2, 0, 2);
			newBrother->left = newLeft;
			newBrother->right = curNode->right;
			newLeft->parent = curNode->right->parent = newBrother;

			Node *newRight = new Node(curNode->mid->val1, 0, 2);
			curNode->right = newRight;
			newRight->parent = curNode;
			//delete(curNode->mid);
			curNode->mid = NULL;
			curNode->val2 = 0;
			curNode->type = 2;

			//curNode = split3(lift, curNode->parent, newBrother);
		}

		// if num is t be inserted in right child
		else {
			lift = curNode->val2;

			median = findmedian(num, curNode->right);
			newBrother->val1 = median;
			newBrother->left = new Node(curNode->right->val1, 0, 2);
			newBrother->right = new Node(curNode->right->val2, 0, 2);
			newBrother->left->parent = newBrother->right->parent = newBrother;

			curNode->val2 = 0;
			curNode->right = curNode->mid;
			curNode->mid = NULL;
			curNode->type = 2;

			//curNode = split3(lift, curNode->parent, newBrother);
		}

		// add level
		if (curNode->parent == NULL) {
			Node *newRoot = new Node(lift, 0, 2);
			newRoot->left = curNode;
			newRoot->right = newBrother;
			newRoot->left->parent = newRoot->right->parent = newRoot;

			curNode = newRoot;
			return curNode;
		}

		curNode = split3(lift, curNode->parent, newBrother);
	}
}

int Tree::findmedian(int num, Node *curNode)
{
	int median = 0;
	if (num < curNode->val1) {
		median = curNode->val1;
		curNode->val1 = num;
	}
	else if (num < curNode->val2)
		median = num;
	else {
		median = curNode->val2;
		curNode->val2 = num;
	}
	return median;
}

void Tree::display()
{
	display(root, 4);
}

void Tree::display(Node *curNode, int n)
{
	if (curNode != NULL) {
		if (curNode->right)
			display(curNode->right, n + 4);

		if (n)
			cout << setw(n) << " ";
		if (curNode->right)
			cout << " /\n" << setw(n) << " ";

		if (curNode->type == 2)
			std::cout << curNode->val1 << endl;
		else if (curNode->type == 3)
			cout << curNode->val1 << "," << curNode->val2;

		if (curNode->mid) {
			cout << "- ";
			display(curNode->mid, 0);
		}

		if (curNode->left) {
			cout << setw(n) << " " << " \\\n";
			display(curNode->left, n + 4);
		}
	}
}

Node * Tree::search(int num, Node *curNode)
{
	if (curNode->left == NULL && curNode->mid == NULL && curNode->right == NULL)
		return curNode;
	else if (num < curNode->val1)
		search(num, curNode->left);
	else if (num < curNode->val2)
		search(num, curNode->mid);
	else
		search(num, curNode->right);
}