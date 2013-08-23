#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int no_of_test , N;
    int flag, i, count;
    char input;
    cin>>no_of_test;
    while(no_of_test)
    {
        cin>>N;
        flag = -1;
        count = 0;
        for(i=0;i<N;i++)
        {
            cin>>input;
            if(flag == -1 && input=='0')
            {
                count++;
                flag = 0;
                continue;
            }
            if(flag == -1 && input=='1')
            {
                flag = 1;
                continue;
            }
            if((flag == 0) && input=='0')
            {
                count++;
                continue;
            }
            if((flag == 0) && input=='1')
            {
                count--;
                flag = 1;
                continue;
            }
            if(flag == 1 && input=='0')
            {
                flag = -1;
                continue;
            }
        }
        cout<<count<<"\n";
        no_of_test--;
    }
    return 0;
}
