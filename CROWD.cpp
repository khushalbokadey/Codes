#include<iostream>
using namespace std;

int main()
{
    long long N , ans;
    int no_of_test;

    cin>>no_of_test;
    while(no_of_test)
    {
        cin>>N;
        ans = ((((N-2)%1000000007)*((N-1)%1000000007))/2)%1000000007;
        cout<<ans<<"\n";
        no_of_test--;
    }
    return 0;
}
