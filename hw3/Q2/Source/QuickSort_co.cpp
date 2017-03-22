#include<iostream>
#include<fstream>
#include<sys/time.h>
#include<stdlib.h>

using namespace std;

int arr1[2000000] = {0};

void median(int *, int, int);
int partition(int *, int, int);
void qs(int *, int, int);
void insertion(int *);

int main(int argc, char **argv)
{
	int N = 0;
	N = atoi(argv[1]);
	cout << N << endl;

	struct timeval start, end, start1, end1;
	int counter = 0;
	int tmp = 0;

	ifstream ifile("../Data/data.txt");
	if(ifile.is_open()){
		while(!ifile.eof() && counter<N){
			ifile >> tmp;
			arr1[counter] = tmp;
			counter++;
		}
	}
	ifile.close();

	gettimeofday(&start, NULL);
	qs(arr1, 0, N - 1);
	gettimeofday(&end, NULL);
	cout << "Quicksort Runtime: " << 1000000*(end.tv_sec-start.tv_sec)+end.tv_usec-start.tv_usec << endl;

	return 0;
}

/* find the median of three and swap with the first element */
void median(int *arr, int hi, int lo)
{
	int mid = lo + (hi-lo)/2;
	int tmp = 0, index = 0;
	if(arr[lo] > arr[mid]){
		if(arr[lo] < arr[hi])
			return;
		else if(arr[mid] > arr[hi])
			index = mid;
		else
			index = hi;
	}
	else if(arr[lo] < arr[mid]){
		if(arr[mid] < arr[hi])
			index = mid;
		else if(arr[hi] > arr[lo])
			index = hi;
		else
			return;
	}
	else
		return;
	tmp = arr[index];
	arr[index] = arr[lo];
	arr[lo] = tmp;
	return;
}

int partition(int *arr, int start, int stop)
{
	//use the median of three as the pivot
	median(arr, stop, start);
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

void qs(int *arr, int first, int last)
{
    int r = 0;
    if(first<last){
		//use insertion sort when input size is less or equal than 10
		if(last <= first + 10 -1){
			insertion(arr);
			return;
		}
        r = partition(arr, first, last);
        qs(arr, first, r-1);
        qs(arr, r+1, last);
    }
}

//insertion sort
void insertion(int *a)
{
	int m = 0;
	int tmp = 0;
	for(int i=0; i<10; i++){
		for(int j=i; j>0; j--){
			if(a[j]<a[j-1]){
				tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
			}
			else
				break;
		}
	}
}
