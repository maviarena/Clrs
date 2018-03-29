#include<iostream>
using namespace std;

int printArray(int arr[], int size)
{
	for(int i = 0; i<= size; i++)
		cout<<arr[i]<<",";
	cout<<endl<<endl;
}
void maxHeapify(int arr[], int index, int size)
{
	if(index > size)
		return;

	int rightIndex = 2*(index + 1);
	int leftIndex = rightIndex -1;

	int largest = index;

	if((leftIndex <= size) && (arr[leftIndex] > arr[largest]))
		largest = leftIndex;
	if((rightIndex <= size) && (arr[rightIndex] > arr[largest]))
		largest = rightIndex;

	if(largest != index)
	{
		int temp = arr[index];
		arr[index] = arr[largest];
		arr[largest] = temp;
		maxHeapify(arr, largest, size);
	}	
}

int heapMax(int arr[], int size)
{
	if(size>0)
		return arr[0];
	else 
		return -1;
}


void heapExtractMax(int arr[], int &max, int &size)
{
	if(size == 0)
		return;
	else
	{
		max = arr[0];
		arr[0] = arr[size];
		size -= 1;
		maxHeapify(arr, 0, size);
	}
}

void heapIncreaseKey(int arr[], int index, int key, int size)
{
	if(index > size)
		return;

	if(arr[index] > key)
		return;
	
	printArray(arr,size);

	arr[index] = key;

	int parent = (index - 1)/2;

	while((arr[index] > arr[parent]) && parent >= 0)
	{

		/*
		int temp = arr[index];
		arr[index] = arr[parent];
		arr[parent] = temp;
		*/
		/* 6.5-6 Excercise Show how to use the idea of inner loop of INSERSTION SORT to 
	 	* reduce the three assignments down to just one
		*/
		
		arr[index] = arr[parent];

		index = parent;
		parent = (index - 1)/2;
		printArray(arr,size);
	}
	arr[parent] = key;
}

int main()
{
	int arr[] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
	int size = (sizeof(arr)/sizeof(arr[0])) - 1;
	int max = 0;
	printArray(arr,size);

	heapIncreaseKey(arr, 8, 15, size);
	//heapExtractMax(arr, max, size);
	//cout<<"Max :: "<< max<<endl;
	printArray(arr,size);
	return 0;
}


