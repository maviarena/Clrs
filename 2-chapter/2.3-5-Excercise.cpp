#include<iostream>
using namespace std;

bool binary_search(int arr[], int ele, int start, int end)
{
	cout<<"binary_search(int arr[] , int ele "<<ele<<", int start "<<start<<", int end "<<end<<" )"<<endl;
	if(start < end)
	{
		int mid = (start + end)/2;
		cout<<"Mid :: "<< mid<<" arr["<<mid<<"] = "<<arr[mid]<<endl;
		if (ele == arr[mid])
			return true;
		else if(ele < arr[mid])
			binary_search(arr, ele, start, mid - 1);
		else if(ele > arr[mid])
			binary_search(arr, ele, mid + 1, end);
	}
	else
		return false;
}


int main()
{
	cout<<"True :: "<< bool(true)<<endl;
	int arr[] = {1, 2, 3, 5, 6, 8, 9, 10, 11, 12, 13};

	cout<<binary_search(arr, 13, 0, (sizeof(arr)/sizeof(arr[0])))<<endl;
	return 0;
}

