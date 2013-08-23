#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 0; i < n; i++)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("op1.txt", "w", stdout);
    #endif
}

int temparray[150000][18];
bool flagarray[150000];

int main()
{
    INPUT_FROM_FILE();
    int no_of_test, i , n, k, m, j, x, max1, maxcount, count, noofoperations;
    int possiblen, l, noofchanges;
    bool flag, chk;
    int arr[20], arr1[20];

    no_of_test = in();

    while(no_of_test--)
    {

        n = in();
        k = in();
        m = in();

        fr(i,n)
        {
            arr[i] = in();
        }

        flag=true;
        for(i=0;i<=n-k;i++)
        {
            max1=0;
            maxcount = 0;
            for(j=i;j<i+k;j++)
            {
                max1=max(max1,arr[j]);
            }
            for(j=i;j<i+k;j++)
            {
                if(arr[j]==max1)
                    maxcount++;
            }
            if(maxcount>=m)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            cout<<"0\n";
        }
        else
        {
            possiblen = pow(2,n);
            for(j=0;j<n;j++)
            {
                temparray[0][j] = arr[j];
            }
            for(i=1;i<=possiblen;i++)
            {
                for(j=0;j<n;j++)
                {
                    temparray[i][j] = arr[j];
                }
            }
            for(j=0;j<n;j++)
            {
                x = pow(2,j);
                chk = false;
                count = 0;
                for(i=1;i<=possiblen;i++)
                {
                    if(!chk)
                    {
                        count++;
                    }
                    else
                    {
                        temparray[i][j]++;
                        count--;
                    }
                    if(count==0 || count == x)
                    {
                        chk = !chk;
                    }
                }
            }
            for(i=0;i<=possiblen;i++)
            {
                flagarray[i] = true;
                for(j=0;j<=n-k;j++)
                {
                    max1=0;
                    maxcount = 0;
                    for(l=j;l<j+k;l++)
                    {
                        max1=max(max1,temparray[i][l]);
                    }
                    for(l=j;l<j+k;l++)
                    {
                        if(temparray[i][l]==max1)
                            maxcount++;
                    }
                    if(maxcount>=m)
                    {
                        flagarray[i] = false;
                        break;
                    }
                }
            }
            noofoperations = 18;
            for(i=0;i<=possiblen;i++)
            {
                noofchanges = 0;
                if(flagarray[i])
                {
                    for(j=0;j<n;j++)
                    {
                        if(arr[j]!=temparray[i][j])
                        {
                            noofchanges++;
                        }
                    }
                    noofoperations = min(noofchanges,noofoperations);
                }
                if(noofoperations==1)
                {
                    break;
                }
            }
            if(noofoperations==18)
            {
                noofoperations = -1;
            }
            cout<<noofoperations<<endl;
        }

    }

    return 0;
}
