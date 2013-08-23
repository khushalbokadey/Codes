#include<iostream>
using namespace std;
int main()
{
	long long no_of_test , n ;
	long long arr[1000000000];
	long long count , j , i ;
	//scanf("%I" , &no_of_test);
	cin>>no_of_test;
	while(no_of_test!=0)
	{
		cin>>n;
		count = n;
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
        cout<<arr[0];
		no_of_test--;
	}
	return 0;
}
