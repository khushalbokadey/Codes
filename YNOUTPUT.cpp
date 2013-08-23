#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>

using namespace std;

int main()
{
    int no_of_test, i ,inputs , start , flag , j , k;
    char output[10005][5];
    cin>>no_of_test;
    inputs = pow(no_of_test,2);
    for(i=0;i<inputs;i++)
    {
        scanf("%s",output[i]);
    }
    start = (no_of_test * (no_of_test-1));
    for(i=0;i<no_of_test;i++)
    {
        flag = 1;
        k = start;
        for(j=i*no_of_test;j<i*no_of_test+no_of_test;j++)
        {
            if(strcmp(output[j],output[k]))
            {
                flag = 0;
                break;
            }
            k++;
        }
        if(flag)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}
