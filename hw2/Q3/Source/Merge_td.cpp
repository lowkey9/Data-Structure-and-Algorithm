#include <iostream>
#include <fstream>
#include <sys/time.h>

using namespace std;

int comparison = 0;

void Merge(int *arr, int *aux, int lo, int mid, int hi)
{
	for(int k=lo; k<=hi; k++)
		aux[k] = arr[k];

	int i = lo, j = mid+1;
	for(int k=lo; k<=hi; k++)
	{
		comparison++;
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

	char *input;
	ifstream ifile;
	int *arr = new int[32768];

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
	mergesort(arr, size);
	gettimeofday(&end, NULL);

	cout << "Runtime: " << 1000000*(end.tv_sec-start.tv_sec)+end.tv_usec-start.tv_usec << endl;
	cout << "Comparisons: " << comparison << endl;

	return 0;
}
