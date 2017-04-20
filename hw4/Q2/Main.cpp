#include <iostream>
#include "Node.h"
#include "RBT.h"

using namespace std;

int main()
{
	//3 inputs
	int input1[3] = { 1,3,5 };
	int input2[5] = { 1,3,5,8,12 };
	int input3[10] = { 1,3,5,8,12,13,16,18,19,24 };

	int counter = 1;
	while (counter < 4)
	{
		cout << "Red-Black Tree based on input" << counter << endl;

		//for input 1
		if (counter == 1) {
			//build Red-Black tree
			RBT tree;
			for (int i = 0; i < 3; i++) {
				Node *newNode = new Node(input1[i], true);
				tree.put(newNode);
			}

			//display the tree
			tree.display();
			tree.show();
		}

		//for input 2
		if (counter == 2) {
			//build Red-Black tree
			RBT tree;
			for (int i = 0; i < 5; i++) {
				Node *newNode = new Node(input2[i], true);
				tree.put(newNode);
			}

			//display the tree
			tree.display();
			tree.show();
		}

		//for input 3
		if (counter == 3) {
			//build Red-Black tree
			RBT tree;
			for (int i = 0; i < 10; i++) {
				Node *newNode = new Node(input3[i], true);
				tree.put(newNode);
			}

			//display the tree
			tree.display();
			tree.show();
		}

		counter++;
	}

	cout << endl;

	return 0;
}