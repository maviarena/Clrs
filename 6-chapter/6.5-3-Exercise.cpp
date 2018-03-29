#include<iostream>

using namespace std;

void printArray(int arr[], int size)
{
	for(int i = 0 ; i <= size; i++)
		cout<<arr[i]<<", ";
	cout<<endl;
}


void minHeapify(int arr[], int index, int size)
{
	if(index > size)
		return;
	
	int rightIndex = (index +1) << 1;
	int leftIndex = rightIndex - 1;

	cout << "rightIndex :: "<<rightIndex<<endl;
	cout << "leftIndex :: "<<leftIndex<<endl;

	int smallest = index;

	if((leftIndex <= size) && (arr[leftIndex] < arr[smallest]))
		smallest = leftIndex;
	if((rightIndex <= size) && (arr[rightIndex] < arr[smallest]))
		smallest = rightIndex;

	if(index != smallest)
	{
		int temp = arr[index];
		arr[index] = arr[smallest];
		arr[smallest] = temp;
		minHeapify(arr, smallest, size);
	}
}

int heapMin(int arr[], int size)
{
	if(size == 0)
		return -1;
	else
		return arr[0];
}

void minHeapExtract(int arr[], int &size, int &min)
{
	min = -1;
	if(size == 0)
		return;

	min = arr[0];
	arr[0] = arr[size];
	size -= size;

	minHeapify(arr, 0, size);
}

void heapDecreaseKey(int arr[], int index, int key, int size)
{
	if(index > size)
		return;

	if(arr[index] < key)
		return;

	arr[index] = key;

	int parent = (index - 1) >> 1;
	cout<<" Index :: "<< index<<"||  Parent :: " <<parent<<endl;

	while((parent >= 0) && arr[parent] > arr[index])
	{
		int temp = arr[parent];
		arr[parent] = arr[index];
		arr[index] = temp;
		
		index = parent;
		parent = (index - 1) >> 1;
		cout<<" Index :: "<< index<<"||  Parent :: " <<parent<<endl;
	}
}


int main()
{
        int arr[] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
        int size = (sizeof(arr)/sizeof(arr[0])) - 1;
        int max = 0;
        printArray(arr,size);

        heapDecreaseKey(arr, 5, 6, size);
        //heapExtractMax(arr, max, size);
        //cout<<"Max :: "<< max<<endl;
        printArray(arr,size);
        return 0;
}

