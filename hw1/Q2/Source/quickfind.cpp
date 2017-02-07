#include <iostream>
#include <fstream>
#include <sys/time.h>

using namespace std;

int find(int *a, int n)
{
	return a[n];
}

void uni(int *a, int n1, int n2)
{
	int pid = a[n1];
	int qid = a[n2];

	//check whether pair are connected again
	if(pid==qid)
		return;
	//if pair are not connected
	//connect them and add other elements to the connected set
	else{
		for(int i=0; i<10000; i++){
			if(a[i]==pid)
				a[i] = qid;
		}
	}
}

bool connected(int *a, int n1, int n2)
{
	return find(a, n1) == find(a, n2);
}

void unionfind(int * a, int num1, int num2)
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
	while(!ifile.eof()){
		ifile >> num1 >> num2;

		//do the quick find version union find
		gettimeofday(&start, NULL);
		unionfind(arr, num1, num2);
		gettimeofday(&end, NULL);

		duration += 1000000*(end.tv_sec-start.tv_sec)+end.tv_usec-start.tv_usec;
	}

	cout << "Runtime: " << duration << "ms" << endl;
	return 0;
}
