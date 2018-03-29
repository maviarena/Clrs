#include<iostream>
using namespace std;

void maxHeapify(int arr[], int index, int size)
{
	while(1)
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
		}
		index = largest;
	}
}

int main()
{
	int arr[]={27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};

	int size = sizeof(arr)/sizeof(arr[0]);

	maxHeapify(arr, 2, size - 1);

	return 0;
}
