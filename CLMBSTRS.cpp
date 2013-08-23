#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<algorithm>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 0; i < n; i++)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
}

long long int NumberOfSetBits(long long int u)
{
     unsigned int uCount;

     uCount = u - ((u >> 1) & 033333333333) - ((u >> 2) & 011111111111);
     return ((uCount + (uCount >> 3)) & 030707070707) % 63;
}

long long int fibo[1000002];

int main()
{
    INPUT_FROM_FILE();
    long long int no_of_test, N, i, j, G, M;

    no_of_test = in();

    for(i=1; i<=1000000; i++)
    {
        if(i==1 || i==2)
        {
            fibo[i] = i % 1000000007;
        }
        else
        {
            fibo[i] = ((fibo[i-1] % 1000000007) + (fibo[i-2]% 1000000007)) % 1000000007;
        }
    }

    while(no_of_test--)
    {
        N = in();
        G = in();

        M = fibo[N];
        //cout<<NumberOfSetBits(534400663)<<endl;

        if(NumberOfSetBits(M) == G)
        {
            cout<<"CORRECT\n";
        }
        else
        {
            cout<<"INCORRECT\n";
        }


    }

    return 0;
}
