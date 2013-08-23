#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

bool arr[100000000];
bool chkprime(long);
int main()
{
    long no_of_test , a , b , i;
    scanf("%ld" , &no_of_test);
    while(no_of_test!=0)
    {
        scanf("%ld %ld" , &a , &b);
        for(i=a;i<=b;i++)
        {
            if(i!=1)
            {
                if(chkprime(i))
                {
                    cout<<i<<"\n";
                }
            }
        }
        cout<<"\n";
        no_of_test--;
    }
    return 0;
}

bool chkprime(long n)
{
    long i , j , k;
    fill(&arr[0] ,&arr[n+1] , true);
    for(i=2;i<=n/2;i++)
    {
        if(arr[i]==true)
        {
            k=2;
            for(j=2*i;j<=n;j=i*k)
            {
                arr[j] = false;
                k++;
            }
        }
    }
    for(i=2;i<=n/2;i++)
    {
        if(arr[i]==true)
        {
            if(n%i==0)
            {
                return false;
            }
        }
    }
    return true;
}
