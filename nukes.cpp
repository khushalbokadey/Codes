#include<iostream>
using namespace std;
int main()
{
    long long N , K , A;
    cin>>A>>N>>K;
    N++;
    while(K!=0)
    {
        cout<<A%N<<" ";
        A=A/N;
        K--;
    }
    return 0;
}
