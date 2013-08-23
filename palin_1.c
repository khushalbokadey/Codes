#include<stdio.h>
#include<string.h>

void palin();

char arr[1000003];
int main()
{
    long no_of_test;
    scanf("%d" , &no_of_test);
    while(no_of_test!=0)
    {
        scanf("%s" , &arr);
        palin();
        printf("\n");
        //puts(arr);O
        printf("%s" , arr);
        printf("\n");
        no_of_test--;
    }
    return 0;
}
void palin()
{
    long i , j , len , mid;
    int flag;
    len = strlen(arr);
    flag = 1;
    for(i=0;i<=len/2;i++)
    {
        if(arr[i]!='9' || arr[len-i-1]!='9')
        {
            flag = 0;
            break;
        }
    }
    if(flag==1)
    {
        arr[0]='1';
        for(i=1;i<len;i++)
        {
            arr[i]='0';
        }
        arr[len]='1';
        return;
    }

    flag = 0;

    for(i=0;i<=len/2;i++)
    {
        if(arr[i]>arr[len-i-1])
            flag = 1;
        else if(arr[i]<arr[len-i-1])
            flag = -1;
        arr[len-i-1]=arr[i];
    }
    if(flag==-1 || flag==0)
    {
        j=0;
        if(len%2==0)
            mid = len/2-1;
        else
            mid = len/2;
        while(arr[mid-j]=='9')
        {
            arr[mid-j]='0';
            arr[mid+j]= '0';
            j++;
        }
        arr[mid-j]++;
        //printf("%c",arr[mid-j]);
        arr[len-1-mid+j] = arr[mid-j];
    }
}
