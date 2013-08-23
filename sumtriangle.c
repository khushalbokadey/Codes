#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int rows , no_of_test;
	int **matrix , i , j;
	scanf("%d" , &no_of_test);
	while(no_of_test!=0)
	{
		scanf("%d" , &rows);
		matrix = (int**)calloc(rows , sizeof(int*));
		for(i=1;i<=rows;i++)
		{
			matrix[i] = (int*)calloc(i , sizeof(int));
		}
		for(i=0;i<rows;i++)
		{
			for(j=0;j<=i;j++)
			{
				scanf("%d" , &matrix[i][j]);
			}
		}
		for(i=0;i<rows;i++)
		{
			for(j=0;j<=i;j++)
			{
				printf("%d" , matrix[i][j]);
			}
		}
		no_of_test--;
	}
	return 0;
}
