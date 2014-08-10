#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

int main () {
string s1,s2;
int i,j,m,n,var=0,cmp=1;
cout<<"enter string 1 : \n";
cin>>s1;
cout<<"enter string 2 : \n";
cin>>s2;
if(s1.length()!=s2.length())
cout<<"Not Same";
else{
for(i=0,j=0;i<var;i++,j++){
if(s1.at(i)!=s2.at(j))
    cmp=0;
    break;
}
if(cmp==1)
cout<<"Same\n";
else
cout<<"Not Same\n"
return 0;
}
