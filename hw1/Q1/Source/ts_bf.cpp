#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sys/time.h>

using namespace std;

int ts_bf(int* a, int len)
{
	int count = 0;
	for(int i=0; i<len; i++)
		for(int j=i+1; j<len; j++)
			for(int k=j+1; k<len; k++)
				if(a[i] + a[j] + a[k] == 0)
					count++;
	return count;
}

int main(int argc, char **argv)
{
	struct timeval start, end;

	char *input;
	ifstream ifile;
	int *arr = new int[8192];

	input = argv[1];
	ifile.open(input, ios::in);
	int tmp = 0;
	int i = 0;
	while(!ifile.eof()){
		ifile >> tmp;
		arr[i] = tmp;
		i++;
	}
	int size = i-1;
	cout << size << endl;
	ifile.close();

	gettimeofday(&start, NULL);
	cout << ts_bf(arr, size) << "\t";
	gettimeofday(&end, NULL);

	cout << "Runtime: " << 1000000*(end.tv_sec-start.tv_sec)+end.tv_usec-start.tv_usec << "ms" << endl;

	return 0;
}
