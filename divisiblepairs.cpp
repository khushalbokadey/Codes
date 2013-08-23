#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    long long N , M , no_of_test , i ,count;
    cin>>no_of_test;
    while(no_of_test--)
    {
        cin>>N;
        cin>>M;
        count = 0;
        for(i=M ; i<=N+N ; i=i+M)
        {
            if(i<=N)
            {
                count += i/2;
            }
            else
            {
                count = count + (N-(i-N))/2;
            }
        }
        cout<<"\n"<<count;
    }
    return 0;
}
