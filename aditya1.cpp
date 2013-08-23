#include<iostream.h>

//using namespace std;

int main()
{
int n,k,i,z=0,j,temp=0,l;
long a[1000],b[1000];
cin>>n>>k;
for(i=0;i<n;i++)
{
cin>>a[i];
}
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
b[z]=a[i]^a[j];
z++;
}
}
for(i=0;i<z;i++)
{
l=i;
for(j=i+1;j<z;j++)
{
if(b[j]<b[l])
{
l=j;
}
}
temp=b[i];
b[i]=b[l];
b[l]=temp;
}
for(i=0;i<k;i++)
{
cout<<b[i]<<" ";
}
return 0;
}
