#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

bool arr[100000003];
void chkprime(long,long);
int main()
{
    long no_of_test , a , b , i , j ,k;
    scanf("%ld" , &no_of_test);
    while(no_of_test!=0)
    {
        scanf("%ld %ld" , &a , &b);
        fill(&arr[0] ,&arr[b+1] , true);
        for(i=2;i<=b;i++)
        {
            if(arr[i]==true)
            {
                k=2;
                for(j=2*i;j<=b;j=i*k)
                {
                    arr[j] = false;
                    k++;
                }
            }
        }
        chkprime(a,b);
        cout<<"\n";
        no_of_test--;
    }
    return 0;
}

void chkprime(long a , long b)
{
    long i;
    for(i=a;i<=b;i++)
    {
        if(i!=1)
        {
            if(arr[i]==true)
            {
                cout<<i<<"\n";
            }
        }
    }
}
