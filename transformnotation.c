#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
	char arr[400] , ans[400];
	int i , j , k, x , no_of_test , len;
	char operator[400] , operand[400];
	scanf("%d",&no_of_test);
	while(no_of_test!=0)
	{
		fflush(stdin);
		gets(arr);
		len = strlen(arr);
		j = 0;
		k = 0;
		for(i=0;i<len;i++)
		{
			if(arr[i]=='(')
			{
				operator[j] = arr[i];
				j++;
			}
			else if(arr[i] == ')')
			{
				j--;
				while(operator[j]!='(')
				{
					ans[k] = operator[j];
					j--;
					k++;
				}
			}
			else if(arr[i]>='a' && arr[i]<='z')
			{
				ans[k] = arr[i];
				k++;
			}
			else
			{
				operator[j] = arr[i];
				j++;
			}
		}
		len = strlen(ans);
        fflush(stdin);
        printf("\n");
		/*for(i=0;i<len;i++)
		{
			printf("%c" , ans[i]);
		}*/
        cout<<ans;
		no_of_test--;
	}
}
