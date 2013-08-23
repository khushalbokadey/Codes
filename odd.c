#include<iostream>
using namespace std;
int main()
{
	long long no_of_test , n ;
	long long *arr;
	long long count , j , i ;
	cin>>no_of_test;
	while(no_of_test!=0)
	{
		//scanf("%I" , &n);
		cin>>n;
		count = n;
		arr = (long long*)calloc(n , sizeof(long long));
		for(j=0;j<n;j++)
		{
			arr[j] = j+1;
		}
		while(count!=1)
		{
			j = count/2;
			i=0;
			while(i<=j)
			{
				arr[i] = arr[i*2+1];
				i++;
			}
			count = i-1;
		}
		//printf("\n%I" , arr[0]);
        cout<<arr[0];
		no_of_test--;
	}
	return 0;
}
