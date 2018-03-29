#include<iostream>
using namespace std;

void printArray(int arr[], int size)
{
	for(int i = 0; i<= size; i++)
		cout<<arr[i]<<",";
	cout<<endl;
}

int partition(int arr[], int start, int end, int size)
{
	if((start < 0) && (end > size))
		return -1;

	int pivot = arr[end];

	int index = start-1, i = -1;

	for(int i = start; i < end; i++)
	{
		if(arr[i] > pivot)
		{
			++index;
			int temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
		}
	}

	++index;
	arr[end] = arr[index];
	arr[index] = pivot;
        printArray(arr, size);
	return index;

}

void quickSort(int arr[], int start, int end, int size)
{
	if(start < end)
	{
		int pivot = partition(arr, start, end, size);
	       	quickSort(arr, start, pivot - 1, size);	
	       	quickSort(arr, pivot + 1, end, size);	
	}
}


int main()
{
        int arr[]={13, 19, 9, 5, 12, 8, 7, 4, 21, 11, 6, 11};
        int size = (sizeof(arr)/sizeof(arr[0]) -1);
        printArray(arr, size);
        quickSort(arr, 0, size, size);
        return 0;
}

