#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
    char arr[100005];
    int i , no_of_test , len , j , k;
    long sum;

    cin>>no_of_test;
    while(no_of_test)
    {
        scanf("%s",arr);
        len = strlen(arr);
        sum = len;
        for(i=1;i<len;i++)
        {
            for(j=i,k=0 ; j<len;k++,j++)
            {
                if(arr[j]!=arr[k])
                {
                    break;
                }
                else
                {
                    sum++;
                }
            }
        }
        cout<<sum<<"\n";
        no_of_test--;
    }

    return 0;
}
