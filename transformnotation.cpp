#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
	char arr[400] , ans[400];
	int i , j , k, x , no_of_test , len , count;
	char operato[400] , operand[400];
	scanf("%d",&no_of_test);

	while(no_of_test!=0)
	{
		//gets(arr);
		count = 0;
		scanf("%s" , &arr);
		len = strlen(arr);
		j = 0;
		k = 0;
		for(i=0;i<len;i++)
		{
			if(arr[i]=='(')
			{
				operato[j] = arr[i];
				j++;
			}
			else if(arr[i] == ')')
			{
				j--;
				while(operato[j]!='(')
				{
					ans[k] = operato[j];
					j--;
					k++;
				}
			}
			else if(arr[i]>='a' && arr[i]<='z')
			{
				ans[k] = arr[i];
				k++;
				count++;
			}
			else
			{
				operato[j] = arr[i];
				j++;
				count++;
			}
		}
		len = strlen(ans);
        printf("\n");
		for(i=0;i<count;i++)
		{
			printf("%c" , ans[i]);
		}
        //cout<<ans;
		no_of_test--;
	}
}