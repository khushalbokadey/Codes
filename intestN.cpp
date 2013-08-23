#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
 long k, ti;
  int n,ctr=0;
  cin>>n>>k;
  while(n--)
  {
  cin>>ti;
  if(ti%k==0)
  ctr++;
  }
  cout<<ctr;

return 0;
}
