#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int x;
    float y;
    cin>>x>>y;
    if(x%5==0 && y-x-0.5>0)
    cout<<y-x-0.5;

    return 0;
}
