#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int t, tc, i, size;		//tc is for test case and t is for loop for test cases.
	char str[2003];
	int num[1000];
	scanf("%d", &tc);
	for(t=0;t<tc;t++)
	{
		cin.getline(str, 2003, '\n');	//taking input as string
		for(i=0;i<strlen(str);i+=2) 	//converting string to integer array
		{
			num[i/2] = str[i]-48;
		}
		size = i/2;			//storing size of array
		i = 0;
		if(num[size-1] == 9)		//checking last digit
		{
			while(num[size-i-1] == 9 && size-i-1 >= 0)	//loop to from last till digits are equal to 9
			{
				num[size-i-1] = 0;		//after this loop all the last 9's will become zero, 4769 --> 4760, 99999 --> 00000
				i++;
			}
		}
		if(size-i-1 >= 0) num[size-i-1]++;		//check if all zeroes, ie size > i+1 if not print "1 " else increment current value 4769 --> 4770, 99999 --> 100000
		else printf("1 ");
		for(i=0;i<size;i++)
			printf("%d ", num[i]);
		printf("\n");
	}
	return 0;
}
