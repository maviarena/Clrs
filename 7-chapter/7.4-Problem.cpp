#include<iostream>
using namespace std;

void printArray(int arr[], int size)
{
	for(int i =0 ;i<= size; i++)
		cout<<arr[i]<<",";
	cout<<endl;
}

int partition(int arr[], int start, int end, int size)
{
	if((start < 0 ) || (end > size))
		return -1;

	int i = start - 1;
	int j = end + 1;

	int pivot = arr[start];

	while(true)
	{
		do{ j--; } while (arr[j] <= pivot);
		do{ i++; } while (arr[i] >= pivot);

		if(i < j)
		{
			int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
		}
		else
		{	
			printArray(arr, size);
			cout<<"i :: "<<i<<"  j :: "<<j<<"  pivot = "<<arr[j]<<endl;	
			return j;
		}
	}	
}

void quickSort(int arr[], int start, int end, int size)
{
	/*
	if(start < end)
	{
		int pivot = partition(arr, start, end, size);
		quickSort(arr, start, pivot - 1, size);
		quickSort(arr, pivot + 1, end, size);
	}*/

	while(start < end)
	{
		int pivot = partition(arr, start, end, size);
		quickSort(arr, start, pivot - 1, size);
		start = pivot + 1;

	}
}

int main()
{
	int arr[] = {13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 21};
	int size = (sizeof(arr)/sizeof(arr[0])) - 1;

	printArray(arr, size);
	quickSort(arr, 0, size, size);
	printArray(arr, size);
}
