/* main function of question 3 */
#include<iostream>
#include<fstream>
#include"Node.h"
#include"Tree.h"

using namespace std;

int main()
{
	int N = 1000000;
	Node *nullPtr = NULL;
	BSTree t(nullPtr);

	ifstream ifile("../Data/hw3-q3-data.txt");
	if (ifile.is_open()) {
		int counter = 0, tmp = 0;
		while (!ifile.eof() && counter < N)
		{
			ifile >> tmp;
			//cout << tmp << " ";
			t.insert(tmp);
			counter++;
		}
		//cout << endl;
	}
	ifile.close();

	int r15 = t.rank(15);
	cout << "value of rank(15): " << r15 << endl;

	int s9 = t.select(9);
	if (s9 == -1)
		cout << "No such node" << endl;
	else
		cout << "value of select(9): " << s9 << endl;

	return 0;
}
