#include<iostream>
using namespace std;
long long power(long );
int main()
{
    long no_of_test , N , i ;

    long long sum , powerof2;

    cin>>no_of_test;
    while(no_of_test)
    {
        sum = 2;
        cin>>N;
        for(i=2;i<=N;i++)
        {
            if(i%2==0)
            {
                powerof2 = power(i/2);
            }
            sum = (sum % 1000000007) + (powerof2 % 1000000007);
        }
        cout<<sum<<"\n";
        no_of_test--;
    }
    return 0;
}

long long power(long n)
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
