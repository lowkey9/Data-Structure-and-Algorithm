#include <iostream>
#include <fstream>
#include <sys/time.h>

using namespace std;

int find(int *a, int n)
{
	//find the root of element n
	while(n!=a[n])
		n = a[n];
	return a[n];
}

void uni(int *a, int n1, int n2)
{
	int root1 = find(a, n1);
	int root2 = find(a, n2);

	//check whether pair are connected again
	if(root1==root2)
		return;
	//if they are not connected
	//let the latter on be the first one's root
	else{
		a[n1] = n2;
	}
}

bool connected(int *a, int n1, int n2)
{
	return find(a, n1) == find(a, n2);
}

void quickunion(int * a, int num1, int num2)
{
	//if pair are connected, print info
	if(connected(a, num1, num2))
		return;
	//if pair are not connected, connect them and then print pair
	else{
		uni(a, num1, num2);
	}
}

int main(int argc, char **argv)
{
	struct timeval start, end;

	char *input;
	ifstream ifile;
	int *arr = new int[10000];

	//initial the array
	for(int i=0; i<10000; i++)
		arr[i] = i;

	input = argv[1];
	ifile.open(input, ios::in);
	int num1 = 0, num2 = 0;
	double duration = 0.0;

	//read pairs from data file
	//there while be one more pair due to the last blank line
	while(!ifile.eof()){
		ifile >> num1 >> num2;

		gettimeofday(&start, NULL);
		quickunion(arr, num1, num2);
		gettimeofday(&end, NULL);

		duration += 1000000*(end.tv_sec-start.tv_sec)+end.tv_usec-start.tv_usec;
	}

	cout << "Runtime: " << duration << "ms" << endl;
	return 0;
}
