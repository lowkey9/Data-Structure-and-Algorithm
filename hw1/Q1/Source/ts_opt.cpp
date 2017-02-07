#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sys/time.h>

using namespace std;

//three sum function
int ts_opt(int *a, int len)
{
	int count = 0;
	int sum = 0;

	for(int i=0; i<len; i++){
		for(int j=i+1; j<len; j++){
			sum = a[i] + a[j];
			int lo = 0, hi = len-1;
			while(lo<=hi){
				int mid = lo+(hi-lo)/2;
				if(sum < a[mid])
					hi = mid - 1;
				else if(sum > a[mid])
					lo = mid + 1;
				else
					count++;
			}
		}
	}
	return count;
}

//quick sort
int dive(int *arr, int start, int stop)
{
	int pivot = arr[start];
	int index = start;
	int j = 0;
	
	for(j=start+1; j<=stop; j++){
		if(arr[j]<=pivot){
			index++;
			int tmp = arr[index];
			arr[index] = arr[j];
			arr[j] = tmp;
		}
	}
	
	arr[start] = arr[index];
	arr[index] = pivot;
	return index;
}

void quicksort(int *arr, int first, int last)
{
	int r = 0;
	if(first < last){
		r = dive(arr, first, last);
		quicksort(arr, first, r-1);
		quicksort(arr, r+1, last);
	}
}

int main(int argc, char **argv)
{
	struct timeval start, end;

	char *input;
	ifstream ifile;
	int *arr = new int[8192];

	//initialize vector using data file
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

	//sort the array using quick sort
	quicksort(arr, 0, size-1);

	gettimeofday(&start, NULL);
	cout << ts_opt(arr, size) << "\t";
	gettimeofday(&end, NULL);

	cout << "Runtime: " << 1000000*(end.tv_sec-start.tv_sec)+end.tv_usec-start.tv_usec << "ms" << endl;

	return 0;
}
