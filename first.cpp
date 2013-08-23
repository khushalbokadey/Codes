#include<iostream>
using namespace std;

template <class T>

T& max (T& a , T& b)
{
    if(a>b)
        return a;
    return b;
}

int main()
{
    cout<<max(2,3);
    cout<<max<int>('a',3);
    return 0;
}
