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

void Sort(int *arr, int size)
{
	int aux[size];
	for(int sz=1; sz<size; sz=sz+sz)
		for(int lo=0; lo<size-sz; lo+=(sz+sz))
			Merge(arr, aux, lo, lo+sz-1, min(lo+sz+sz-1, size-1));
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
	
	gettimeofday(&start, NULL);	
	Sort(arr, size);
	gettimeofday(&end, NULL);

	for(int k=0; k<20; k++)
		cout << arr[k] << ",";
	cout << endl;

	cout << "Runtime: " << 1000000*(end.tv_sec-start.tv_sec)+end.tv_usec-start.tv_usec << endl;
	cout << "Comparisons: " << comparison << endl;

	return 0;
}
