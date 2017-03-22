#include<iostream>
#include<fstream>
#include<sys/time.h>
#include<stdlib.h>

using namespace std;

int arr1[10000000] = {0};
int arr2[10000000] = {0};

int partition(int *, int, int);
void qsR(int *, int, int);
void qsI(int *, int, int);

int main(int argc, char **argv)
{
	int N = 0;
	N = atoi(argv[1]);
	cout << N << endl;

	struct timeval start1, start2, end1, end2;
	int counter = 0;
	int tmp = 0;

	ifstream ifile("../Data/data.txt");
	if(ifile.is_open()){
		while(!ifile.eof() && counter<N){
			ifile >> tmp;
			arr1[counter] = arr2[counter] = tmp;
			//arr2[counter] = tmp;
			counter++;
		}
	}
	ifile.close();

	gettimeofday(&start1, NULL);
	qsR(arr1, 0, N - 1);
	gettimeofday(&end1, NULL);
	cout << "Recursive Quicksort Runtime: " << 1000000*(end1.tv_sec-start1.tv_sec)+end1.tv_usec-start1.tv_usec << endl;

	gettimeofday(&start2, NULL);
	qsI(arr2, 0, N - 1);
	gettimeofday(&end2, NULL);
	cout << "Iterative Quicksort Runtime: " << 1000000*(end2.tv_sec-start2.tv_sec)+end2.tv_usec-start2.tv_usec << endl;

	return 0;
}


int partition(int *arr, int start, int stop)
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

void qsR(int *arr, int first, int last)
{
    int r = 0;
    if(first<last){
        r = partition(arr, first, last);
        qsR(arr, first, r-1);
        qsR(arr, r+1, last);
    }
}

void qsI(int *arr, int first, int last)
{
	// Create an auxiliary stack
	int stack[ last - first + 1 ];

	// initialize top of stack
	int top = -1;

	// push initial values of first and last to stack
	stack[ ++top ] = first;
	stack[ ++top ] = last;

	// Keep popping from stack while is not empty
	while ( top >= 0 ){
		// Pop first and last
		last = stack[ top-- ];
		first = stack[ top-- ];
		
		// Set pivot element at its correct position in sorted array
		int p = partition(arr, first, last);

		// If there are elements on left side of pivot then push left side to stack
		if ( p-1 > first ){
			stack[ ++top ] = first;
			stack[ ++top ] = p - 1;
		}
		
		// If there are elements on right side of pivot then push right side to stack
		if ( p+1 < last ){
			stack[ ++top ] = p + 1;
			stack[ ++top ] = last;
		}
	}
}
