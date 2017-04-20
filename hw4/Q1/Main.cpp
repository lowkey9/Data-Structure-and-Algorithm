#include <iostream>
#include "Node.h"
#include "Tree.h"

using namespace std;

int main()
{
	//3 inputs
	int input1[3] = { 1,3,5 };
	int input2[5] = { 1,3,5,8,12 };
	int input3[10] = { 1,3,5,8,12,13,16,18,19,24 };

	/*
	int input[9] = { 19,5,1,18,3,8,24,16,12 };
	Tree tree;
	for (int i = 0; i < 9; i++) {
		tree.insert(input[i]);
	}

	cout << "test tree" << endl;
	tree.display();
	*/
	
	int counter = 1;
	while (counter < 4)
	{
		cout << "Red-Black Tree based on input" << counter << endl;

		//for input 1
		if (counter == 1) {
			Tree tree;
			for (int i = 0; i < 3; i++) {
				tree.insert(input1[i]);
			}

			cout << "tree 1" << endl;
			tree.display();
		}

		//for input 2
		if (counter == 2) {
			Tree tree;
			for (int i = 0; i < 5; i++) {
				tree.insert(input2[i]);
			}

			cout << "tree 2" << endl;
			tree.display();
		}

		
		//for input 3
		if (counter == 3) {
			Tree tree;
			for (int i = 0; i < 10; i++) {
				tree.insert(input3[i]);
			}

			cout << "tree 3" << endl;
			tree.display();
		}
		
		counter++;
	}
	
	return 0;
}