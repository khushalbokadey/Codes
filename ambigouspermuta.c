#include<stdio.h>
int main()
{
	long n , i;
	long *arr , *newarr;
	int flag;
	scanf("%ld" , &n);
	while(n!=0)
	{
		arr = (long*)malloc(n*sizeof(long));
		newarr = (long*)malloc(n*sizeof(long));
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			newarr[arr[i]-1] = i+1;
		}
		flag = 1;
		for(i=0;i<n;i++)
		{
			if(arr[i]!=newarr[i])
			{
				flag=0;
				break;
			}
		}
		if(flag==0)
			printf("not ambiguous\n");
		else
			printf("ambiguous\n");
		scanf("%ld" , &n);
	}
	return 0;
}
