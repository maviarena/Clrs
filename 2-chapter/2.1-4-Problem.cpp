#include<iostream>

using namespace std;

int main()
{
	int A[] = {1,0,0,0}; //binary reperentation of 08
	int B[] = {1,0,0,1}; //binary reperentation of 09

	int size = sizeof(A)/sizeof(A[0]);
	cout<<"size::"<< size<<endl;
	int C[size+1];

	int sum , carry = 0;
	
	
	int i = size;
	for(; i!=0; i--)
	{
		sum = 0;
		sum = A[i - 1] + B[i - 1] + carry;
		C[i] = sum % 2;

		if (sum > 1) carry = 1;
		else carry = 0;

		if( (i - 1) == 0)
			C[i-1] = carry;

	}

	 for(int j= 0; j <=size; j++)
		 cout<<C[j]<<",";

	 cout<<endl;
	return 0;
}
