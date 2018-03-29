#include<iostream>

using namespace std;

int main()
{
	int arr[] = {6, 7, 1, 3, 9, 2, 4};

	int size = sizeof(arr)/sizeof(arr[0]);
	int index = 0;
	int i;

	cout<< size<<endl;

	for(i = 0; i<size ; i++)
	{
		cout<< arr[i]<<",";
	}
	cout<<endl;	

	for(i = 0; i<size-1 ; i++)
	{
		index = i;
		for(int j = i+1 ; j < size; j++)
		{
			if(arr[j] < arr[index])
				index = j;
		}
		cout<<index<<","<<i<<endl;
		int temp = arr[index];
		arr[index] = arr[i];
		arr[i] = temp;
	}

	for(i = 0; i<size ; i++)
	{
		cout<< arr[i]<<",";
	}
	cout<<endl;	

	return 0;
}
