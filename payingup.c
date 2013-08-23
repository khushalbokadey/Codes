#include<stdio.h>
int notes , money , value[20];
int paying(int , int);
int main()
{
	int no_of_test;
	int i , j , temp , k , flag;
	scanf("%d" , &no_of_test);
	while(no_of_test!=0)
	{
		scanf("%d %d" , &notes , &money);
		for(i=0;i<notes;i++)
		{
			scanf("%d" , &value[i]);
			for(j=0;j<=i;j++)
			{
				if(value[i]<value[j])
				{
					k=i;
					while(k!=j)
					{
						temp = value[k];
						value[k] = value[k-1];
						value[k-1] = temp;
						k--;
					}
				}
			}
		}
		flag = 0;
		for(i=notes-1;i>=0;i--)
		{
			if(value[i]>money)
			{
				continue;
			}
			else
			{
				if(paying(i , money)==1)
                {
                    flag = 1;
                    break;
                }
			}
		}
		if(flag == 1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
		no_of_test--;
	}
	return 0;
}
int paying(int i , int money)
{
	int balance ,j;
	if(value[i]==money)
	{
		//printf("Yes\n");
		return 1;
	}
	if(i==0 && value[i]!=money)
	{
		//printf("No\n");
		return 0;
	}
	balance = money-value[i];
	for(j=i-1;j>=0;j--)
	{
		if(value[j]>balance)
		{
			continue;
		}
		else
		{
			if(paying(j , balance)==1)
            {
                return 1;
            }
		}
	}
}
