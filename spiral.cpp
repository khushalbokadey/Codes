#include<iostream>
using namespace std;
int main()
{
    unsigned long t , n ,  i , final;
    cin>>t;
    while(t!=0)
    {
        cin>>n;
        n= n-1;
        i = 2*n +1;
        final = i*i + n;
        cout<<"\n"<<final;
        t--;
    }
    return 0;
}
