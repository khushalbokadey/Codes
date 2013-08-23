#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 0; i < n; i++)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

bool myfunction (int i,int j) { return (i>j); }

int main()
{
    INPUT_FROM_FILE();
    int i, N, K, arr[102], noofflowers[101];
    long long int totalcost = 0;

    N = in();
    K = in();

    fr(i,N)
    {
        arr[i] = in();
    }

    sort(arr, arr+N, myfunction);
    fill(noofflowers, noofflowers+K, 0);

    fr(i,N)
    {
        totalcost += arr[i]*(noofflowers[i%K]+1);
        noofflowers[i%K]++;
    }

    cout<<totalcost;

    return 0;
}
