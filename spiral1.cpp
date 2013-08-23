#include<iostream>
using namespace std;
int main()
{
    unsigned long t , n ,  i , final;
    cin>>t;
    while(t!=0)
    {
        cin>>n;
        i = 2*n -1;
        final = i*i + n-1;
        cout<<final;
        t--;
    }
    return 0;
}
