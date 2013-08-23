#include<stdio.h>
int answer[400];
void fact(int);
int main()
{
	int no_of_test , num;
	scanf("%d" , &no_of_test);
	while(no_of_test!=0)
	{
		scanf("%d",&num);
        if(num==1 || num==0)
            printf("%d",1);
        else
            fact(num);

        printf("\n");
		no_of_test--;
	}
	return 0;
}
void fact(int num)
{
	int  value;
	int tempnum , i , j, count , temp;
	tempnum = num;
	i=0;
	while(tempnum!=0)
	{
		answer[i] = tempnum%10;
		tempnum/=10;
		i++;
	}
	temp = 0;
	while(num!=1)
	{

		num--;
		count =0;
		for(j=0;j<i ; j++)
		{
			value = answer[j]*num + temp;
			answer[j] = value%10;
			temp = value/10;
			count++;
		}
		while(temp!=0)
		{
			answer[count] = temp%10;
			temp/=10;
			count++;
		}
		i=count;
	}
	for(j=count-1;j>=0 ; j--)
	{
		printf("%d" , answer[j]);
	}
}
