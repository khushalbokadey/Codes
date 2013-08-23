#include<stdio.h>
#include<math.h>
int ispalin(long);
int isprime(long);
int main()
{
	long number , ans;
	int flag;
    flag = 1;
	scanf("%ld" , &number);
	if(number%2==0)
	{
		ans = number+1;
	}
	else
	{
		ans = number;
		if(ispalin(ans)==1 && isprime(ans)==1)
		{
			flag=0;
		}
	}
	while(flag==1)
	{
		ans+=2;
		if(ispalin(ans)==1 && isprime(ans)==1)
		{
			flag=0;
			break;
		}
	}
	printf("%ld" , ans);
	return 0;
}
int ispalin(long num)
{
	long rev , ans;
	int i;
	rev = num;
	ans = 0;
	while(num!=0)
	{
		ans = (ans*10) + (num%10);
		num/=10;
	}
	if(rev==ans)
	{
		return 1;
	}
	else
		return 0;
}

int isprime(long num)
{
	long sqr_rt , j , i;
	int flag = 1;
	if(num%3==0)
	{
	    return 0;
	}
    sqr_rt = (long)sqrt(num);
	i = 1;
	while(((6*i)-1)<=sqr_rt)
	{
		if((num%((6*i)-1))==0 || (num%((6*i)+1))==0)
		{
			return 0;
		}
		i++;
	}
    return 1;
}
