#include<iostream>

using namespace std;

int main()
{
	int arr[] = {6, 7, 1, 3, 9, 2, 4};
	int size = sizeof(arr)/sizeof(arr[0]);
	for(int k =0 ; k < size; k++)
		cout<<arr[k]<<",";
	cout<<endl;

	
	for(int i=0; i<size -1 ; i++)
	{
		for(int j = size - 1; j != i ; j--)
		{
			if(arr[j] < arr[j-1])
			{
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
		for(int k =0 ; k < size; k++)
			cout<<arr[k]<<",";
		cout<<endl;
	}

	return 0;
}
