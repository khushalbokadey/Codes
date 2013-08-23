#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    long long value ,i , x , y;
    int no_of_test , flag;
    scanf("%d",&no_of_test);
    while(no_of_test--)
    {
        cin>>value;
        flag = 0;
        for(x=0; x<=value;x=x+4)
        {
            if(value%7==0 && value%4==0)
            {
                printf("\n%d",value);
                flag = 1;
                break;
            }
            y = value - x;
            if(y%7==0)
            {
                printf("\n%d",y);
                flag = 1;
                break;
            }

        }
        if(flag==0)
        {
            printf("\n-1");
        }
    }
    return 0;
}
