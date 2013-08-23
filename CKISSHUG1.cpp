#include<iostream>
using namespace std;

long power(long);
int main()
{
    long no_of_test , N , i ;

    long sum;

    cin>>no_of_test;
    while(no_of_test)
    {
        cin>>N;
        if(N%2==1)
        {
            sum = ((2*(power(N/2+1)-1))%1000000007);
        }
        else
        {
            long long powerof2;
            powerof2 = power(N/2);
            sum = ((2*(powerof2-1))%1000000007);
            sum = (sum + ((powerof2)%1000000007))%1000000007;
        }

        cout<<sum<<"\n";
        no_of_test--;
    }
    return 0;
}
long power(long n)
{
    long long powerof2=1;

    if(n==0)
    {
        return powerof2;
    }
    if(n==1)
    {
        return 2;
    }

    if(n%2==0)
    {
        powerof2 = (power(n/2)%1000000007);
        powerof2 = ((powerof2 * powerof2)%1000000007);
    }
    else
    {
        powerof2 = (2 *(power(n-1)%1000000007)%1000000007);
    }
    return powerof2;
}

