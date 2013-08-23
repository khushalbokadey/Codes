#include<stdio.h>
#include<iostream>
#include<new>
using namespace std;

int **matrix , rows;
int maximum;
void sums(int , int , int);

int main()
{
	int no_of_test;
	int i , j;
	int sum;
	scanf("%d" , &no_of_test);
	while(no_of_test!=0)
	{
	    maximum=0;
		cin>>rows;
		matrix = new int*[rows];
		for(i=1;i<=rows;i++)
		{
			matrix[i-1] = new int[i];
		}
		for(i=0;i<rows;i++)
		{
			for(j=0;j<=i;j++)
			{
				scanf("%d" , &matrix[i][j]);
			}
		}
		sum = matrix[0][0];
		sums(0,0,sum);

		printf("%d\n" , maximum);

		no_of_test--;
	}
	return 0;
}

void sums(int i , int j , int sum)
{
    long tempsum;
    tempsum = sum;
	if(i+1==rows-1)
	{
		if((sum+matrix[i+1][j])>maximum)
		{
			maximum = sum+matrix[i+1][j];
		}
		if((sum+matrix[i+1][j+1])>maximum)
		{
			maximum = sum+matrix[i+1][j+1];
		}
	}
	else
	{
		tempsum = sum + matrix[i+1][j];
		sums(i+1,j,tempsum);
		tempsum = sum + matrix[i+1][j+1];
		sums(i+1,j+1,tempsum);
	}
}
