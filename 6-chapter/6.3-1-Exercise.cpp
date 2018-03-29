#include<iostream>
using namespace std;

void maxHeapify(int arr[], int index, int size)
{
		for(int i = 0; i<=size; i++)
			cout<<arr[i] <<",";
		cout<<endl;
		int rightChild = 2*(index+1);
		int leftChild = rightChild - 1;

		if (index > size ) return;
	

		int largest = index;

		if((leftChild < size ) && (arr[leftChild] > arr[largest]))
			largest = leftChild;
		if((rightChild < size)  && (arr[rightChild] > arr[largest]))
			largest = rightChild;

		if(index == largest) return;

		if(index != largest)
		{
			int temp = arr[largest];
			arr[largest] = arr[index];
			arr[index] = temp;
			maxHeapify(arr, largest, size);
		}
}

int main()
{
	int arr[]={5, 3, 17, 10, 84, 19, 6, 22, 9};

	int size = sizeof(arr)/sizeof(arr[0]);

	int mid = size/2;

	for(int i = mid; i>=0 ; i--)
		maxHeapify(arr, i , size - 1);

	return 0;
}
