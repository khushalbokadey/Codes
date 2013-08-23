#include<stdio.h>

int main()
{
    char arr[10];
    int i,j, flag;
    scanf("%s",arr);
    flag = 1;
    for(i=0;i<9;i++)
    {
        if(!(arr[i]>=48 && arr[i]<=57) && arr[i]!='?')
        {
            flag = 0;
            break;
        }
    }
    if(!(arr[9]>=48 && arr[9]<=57) && arr[9]!='X')
    {
        flag = 0;
    }
    if(flag)
    {
        int sum , index , reqd;
        sum = 0;
        for(i=0;i<10;i++)
        {
            if(arr[i]>=48 && arr[i]<=57)
            {
                sum += (10-i)*(arr[i]-48);
            }
            else if(arr[i]=='?')
            {
                index = 10-i;
            }
            else if(arr[i]=='X')
            {
                sum += 10;
            }
        }
        reqd = sum%11;
        reqd = 11 - reqd;
        if(reqd%index == 0)
        {
            printf("%d\n",reqd/index);
        }
        else
        {
            printf("NO SOLUTION POSSIBLE\n");
        }
    }
    else
    {
        printf("INVALID OUTPUT\n");
    }
    return 0;
}
