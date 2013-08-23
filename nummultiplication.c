#include<stdio.h>
int mul(int,int[] , int);
int ans[10];
int main()
{
	int  a , b , i , count;
	int num1[5] ;
	scanf("%d %d" , &a , &b);
	i=0;
	while(b!=0)
	{
		num1[i] = b%10;
		b/=10;N
		i++;
	}
	count = mul(a , num1 , i);
	for(i=count-1;i>=0 ; i--)
	{
		printf("%d " , ans[i]);
	}
	return 0;
}
int mul(int a , int num1[] , int count)
{
	int temp , index , i , num;
	temp = 0 ;
	index = 0;
	for(i=0;i<count;i++)
	{
		num = num1[i]*a + temp;
		ans[i] = num%10;
		temp = num/10;
	}
	while(temp!=0)
	{
		ans[i] = temp%10;
		temp/=10;
		i++;
	}
	return i;
}
