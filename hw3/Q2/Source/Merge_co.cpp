#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sys/time.h>

using namespace std;

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

void Merge(int *arr, int *aux, int lo, int mid, int hi)
{
	for(int k=lo; k<=hi; k++)
		aux[k] = arr[k];

	int i = lo, j = mid+1;
	for(int k=lo; k<=hi; k++)
	{
		if(i>mid)
			arr[k] = aux[j++];
		else if(j>hi)
			arr[k] = aux[i++];
		else if(aux[j]<aux[i])
			arr[k] = aux[j++];
		else
			arr[k] = aux[i++];
	}
}

void Sort(int *arr, int *aux, int lo, int hi)
{
	if(hi<=lo)
		return;
	//use insertion sort when the input size is less or equal than 10
	if(hi <= lo + 10 -1){
		insertion(arr);
		return;
	}
	int mid = lo + (hi-lo)/2;
	Sort(arr, aux, lo, mid);
	Sort(arr, aux, mid+1, hi);
	Merge(arr, aux, lo, mid, hi);
}

void mergesort(int *a, int size)
{
	int aux[size];
	Sort(a, aux, 0, size-1);
}

int main(int argc, char **argv)
{
	struct timeval start, end;

	int num = atoi(argv[1]);
	ifstream ifile;
	int *arr = new int[2000000];

	//input = argv[1];
	ifile.open("../Data/data.txt", ios::in);
	int tmp = 0;
	int i = 0;
	while(!ifile.eof() && i<num){
		ifile >> tmp;
		arr[i] = tmp;
		i++;
	}
	int size = i;
	cout << size << endl;
	ifile.close();

	gettimeofday(&start, NULL);
	mergesort(arr, size);
	gettimeofday(&end, NULL);

	cout << "Runtime: " << 1000000*(end.tv_sec-start.tv_sec)+end.tv_usec-start.tv_usec << endl;
	//cout << "Comparisons: " << comparison << endl;

	return 0;
}
