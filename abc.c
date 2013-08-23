#include<stdio.h>
#include<string.h>
int main()
{
	char arr[1000];
	int no_of_test , len , i , j , flag;
	scanf("%d" , &no_of_test);
	while(no_of_test!=0)
	{
		fflush(stdin);
		scanf("%s" , arr);			/*input of string*/
		len = strlen(arr);
		flag= 1;
		for(i=0;i<len;i++)			/*check if all the   digits are 9???*/
		{
			if(arr[i]!='9')
			{
				flag=0;
			}
		}

		if(flag==1)		/* if all the digits are 9 then just make 1st element 1 and others 0 increasing len by1 */
		{
			arr[0] = '1';
			for(i=1;i<=len;i++)
			{
				arr[i] = '0';
			}
			len++;
		}
		else			/*else go for other numbers*/
		{
			if(arr[len-1]=='9')			/* if last digit is 9 , subtract by 9 as they are ascii codes*/
				arr[len-1]= arr[len-1] -9;
			else				/* else increase  char by 1*/
				arr[len-1]= arr[len-1]  + 1;
			j = len-1;
			if(arr[len-1]=='0')			/* make the changes in the digits accordingly if last is made 0*/
			{
				j--;
				while(arr[j+1]=='0' || j==0)
				{
					if(arr[j]=='9')
						arr[j]= arr[j] -9;
					else
						arr[j]= arr[j]  + 1;
					j--;
				}
			}
		}
		printf("\n");				/* print array*/
		for(i=0;i<len;i++)
		{
			printf("%c" , arr[i]);
		}
		no_of_test--;
	}
	return 0;
}
