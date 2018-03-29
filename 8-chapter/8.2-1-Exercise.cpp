#include<iostream>
using namespace std;

void printArray(int arr[], int size)
{
	for(int i = 0; i<= size; i++)
		cout<<arr[i]<<",";
	cout<<endl;
}

int largest(int arr[], int size)
{
	int large = arr[0];
	for(int i = 0; i<=size; i++)
	{
		if(arr[i] > large)
			large = arr[i];
	}
	return large;
}

void countingSort(int arr[], int size, int outArr[])
{
	if(size < 0)
		return;
	int cSize=largest(arr, size);
	

	int cArr[cSize + 1] = {0};

	cout<<" Out Arr :: ";printArray(outArr, size);
	cout<<" C Arr :: ";printArray(cArr, cSize);

	for(int i = 0; i<=size; i++)
	{
		cArr[arr[i]] += 1;  
	}
	cout<<"C Arr :: ";printArray(cArr, cSize);
	
	for(int i = 1; i<=cSize; i++)
	{
		cArr[i] += cArr[i - 1];  
	}
	cout<<"cArr :: ";printArray(cArr, cSize);

	for(int i = size; i>=0; i--)
	{
		outArr[(cArr[arr[i]]) - 1] = arr[i];
	      	--cArr[arr[i]];
	}
	printArray(outArr, size);
}

int main()
{
	int arr[]={6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2};
	int size = sizeof(arr)/sizeof(arr[0]);
	int outArr[size] = {0};
	printArray(arr, size - 1);

	countingSort(arr, size -1, outArr);
	return 0;
}
