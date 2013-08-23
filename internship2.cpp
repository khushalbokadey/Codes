#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

char* match1(char[] , char[]);
char* match(char[] , char[]);

int main()
{
    char str1[100];
    char str2[100] , *common;
    scanf("%s" , str1);
    scanf("%s" , str2);
    common = match(str1,str2);
    fflush(stdin);
    //cout<<strlen(common);
    for(int i=0;i<strlen(common);i++)
        cout<<common[i];
    return 0;
}
char* match1(char* str1 , char* str2)
{
    char common[100];
    int k=0;
    for(int i=0;i<strlen(str1);i++)
    {
        for(int j =0;j<strlen(str2);j++)
        {
            if(str1[i]==str2[j])
            {
                common[k]=str1[i];
                k++;
            }
        }
    }
    return common;
}
char* match(char[] , char[])
{
    int common[100][2];
    for(int i=0;i<strlen(str1);i++)
    {

    }
}
