#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
    char *cptr;
    int i , j ,k , len;
    cout<<"\n Enter word : ";
    gets(cptr);
    len = strlen(cptr);
    cout<<"\n"<<len;
    return 0;
}
