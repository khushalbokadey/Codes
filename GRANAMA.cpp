#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
}

int chkarr(int[], int[]);

int main()
{
    INPUT_FROM_FILE();
    int arr1[26], arr2[26], i, no_of_test, lenR, lenS;
    char R[1002], S[1002];

    scanf("%d",&no_of_test);

    while(no_of_test--)
    {
        fill(arr1,arr1+26,0);
        fill(arr2,arr2+26,0);

        scanf("%s %s", &R, &S);
        lenR = strlen(R);
        lenS = strlen(S);
        for(i=0 ; i<lenR ; i++)
        {
            arr1[R[i]-97]++;
        }
        for(i=0 ; i<lenS ; i++)
        {
            arr2[S[i]-97]++;
        }

        int flag = chkarr(arr1,arr2);

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

int chkarr(int arr1[], int arr2[])
{
    int i, flag=1;
    for(i=0;i<26;i++)
    {
        if(arr1[i]!=arr2[i])
        {
            flag = 0;
            break;
        }
    }
    if(flag)
    {
        return flag;
    }
    else
    {
        for(i=0;i<26;i++)
        {
            if((arr1[i]!=arr2[i]) && ((arr1[i]>0 && arr2[i]==0) || (arr2[i]>0 && arr1[i]==0)))
            {
                flag = 1;
                break;
            }
            else if(arr1[i]!=arr2[i])
            {
                flag = 0;
            }
        }
    }

    return flag;
}
