#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    char J[103], S[103] ;
    int Jc[150] ,i ,count;
    int no_of_test;
    scanf("%d",&no_of_test);
    while(no_of_test--)
    {
        count=0;
        scanf("%s",J);
        for(i=65;i<=90;i++)
        {
            Jc[i]=0;
        }
        for(i=97;i<=122;i++)
        {
            Jc[i]=0;
        }
        for(i=0;J[i]!='\0';i++)
        {
            Jc[J[i]]=1;
        }
        scanf("\n%s",S);
        for(i=0;S[i]!='\0';i++)
        {
            if(Jc[S[i]]==1)
            {
                count++;
            }
        }
        cout<<"\n"<<count;
    }
    return 0;
}
