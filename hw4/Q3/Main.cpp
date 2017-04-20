#include <iostream>
#include <random>
#include <time.h>
#include "Node.h"
#include "RBT.h"

using namespace std;

int main()
{
	int counter = 1;
	int size = 2000000;

	random_device rd;
	mt19937 gen(rd());
	while (counter < 11)
	{
		cout << "Generating random numbers" << endl;
		//if (counter == 1)
		//	size += 1000000;
		//else
		//	size += 500000;
		cout << "Size: " << size << endl;
		int *arr = new int[size];
		//srand(time(NULL));
		for (int i = 0; i < size; i++) {
			//arr[i] = rand();
			uniform_int_distribution<int> dis(0, size);
			arr[i] = dis(gen);
		}

		//build Red-Black tree
		cout << "Building Red-Black Tree based on random numbers set " << counter << endl;
		RBT tree;
		for (int i = 0; i < size; i++) {
			Node *newNode = new Node(arr[i], true);
			tree.put(newNode);
		}

		//print cost, rotations, splits
		cout << "Total rotations: " << tree.getRotations() << endl;
		cout << "Total splits: " << tree.getSplits() << endl;
		cout << "Total compares: " << tree.getCompares() << endl;

		delete[] arr;
		counter++;
		cout << endl;
	}

	return 0;
}
