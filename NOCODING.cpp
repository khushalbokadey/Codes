#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int main()
{
    int no_of_test , no_of_instructions , maxlength , length;
    int i , j;
    char arr[1003];
    cin>>no_of_test;
    while(no_of_test)
    {
        scanf("%s",arr);
        no_of_instructions=0;
        length = strlen(arr);
        maxlength = length * 11;
        no_of_instructions++;
        for(i=0;i<length;i++)
        {
            if(i==length-1)
            {
                no_of_instructions++;
                break;
            }
            if(arr[i]<arr[i+1])
            {
                no_of_instructions += (arr[i+1]-arr[i]);
                no_of_instructions++;
            }
            else if(arr[i]>arr[i+1])
            {
                no_of_instructions += (26 + arr[i+1] - arr[i]);
                no_of_instructions++;
            }
            else if(arr[i] == arr[i+1])
            {
                no_of_instructions++;
            }
        }
        if(no_of_instructions<=maxlength)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
        no_of_test--;
    }
    return 0;
}
