#include <iostream>
#include <fstream>
#include <sys/time.h>

using namespace std;

int find(int *a, int n)
{
	//find the root of n
	while(n!=a[n]){
		a[n] = a[a[n]];		//let examined node point to its root
		n = a[n];
	}
	return n;
}

void uni(int *a, int *h, int n1, int n2)
{
	int i = find(a, n1);
	int j = find(a, n2);
	//if pair are connected, return
	if(i==j)
		return;
	//if they are not connected
	//connect smaller tree to larger tree
	if(h[i] < h[j]){
		a[i] = j;
		h[j] += h[i];
	}
	else{
		a[j] = i;
		h[i] += h[j];
	}
}

bool connected(int *a, int n1, int n2)
{
	return find(a, n1) == find(a, n2);
}

void wqkuni(int * a, int *h, int num1, int num2)
{
	//if pair are connected, print info
	if(connected(a, num1, num2))
		return;
	//if pair are not connected, connect them and then print pair
	else{
		uni(a, h, num1, num2);
	}
}

int main(int argc, char **argv)
{
	struct timeval start, end;

	char *input;
	ifstream ifile;
	int *arr = new int[10000];
	int *height = new int[10000];

	//initial the array
	for(int i=0; i<10000; i++){
		arr[i] = i;
		height[i] = 1;
	}

	input = argv[1];
	ifile.open(input, ios::in);
	int num1 = 0, num2 = 0;
	double duration = 0.0;

	//read pairs from data file
	//there while be one more pair due to the last blank line
	while(!ifile.eof()){
		ifile >> num1 >> num2;

		gettimeofday(&start, NULL);
		wqkuni(arr, height, num1, num2);
		gettimeofday(&end, NULL);

		duration += 1000000*(end.tv_sec-start.tv_sec)+end.tv_usec-start.tv_usec;
	}

	cout << "Runtime: " << duration << "ms" << endl;
	return 0;
}
