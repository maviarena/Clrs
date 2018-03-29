#include<iostream>

using namespace std;

void maxHeapify(int arr[], int index, int size)
{
	if(index > size) return;

	int rightIndex = 2*(index + 1);
	int leftIndex = rightIndex - 1;
	int largest = index;
	int temp = 0;


	if((rightIndex <= size) && arr[rightIndex] > arr[largest])
		largest = rightIndex;
	if((leftIndex <= size) && arr[leftIndex] > arr[largest])
		largest = leftIndex;

	if(index != largest)
	{
		temp = arr[index];
		arr[index] = arr[largest];
		arr[largest] = temp;

		maxHeapify(arr, largest, size);
	}
}


void maxHeap(int arr[], int size)
{
	int mid = size/2;

	for (int i = mid; i>=0 ; i--)
		maxHeapify(arr, i, size);
}

void heapSort(int arr[], int size)
{
	for(int j = 0; j<= size; j++)
		cout<<arr[j]<<",";
	cout<<endl;

	maxHeap(arr, size);
	for(int j = 0; j<= size; j++)
		cout<<arr[j]<<",";
	cout<<endl;
	
	for(int i = size; i >= 1; i--)
	{
		cout<<"1------"<<i<<endl;
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		cout<<"2------"<<i<<endl;
		maxHeapify(arr, 0, i - 1);
		for(int j = 0; j<= size; j++)
			cout<<arr[j]<<",";
		cout<<endl;
	}
}

int main()
{
	int arr[] = {5, 13, 2, 25, 7, 17, 8, 20, 4};
	int size = sizeof(arr)/sizeof(arr[0]);

	cout<<"Size ::" <<size<<endl;
	heapSort(arr, size - 1);
	return 0;
}
