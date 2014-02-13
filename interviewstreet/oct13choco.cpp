#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<map>
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


int main()
{
    INPUT_FROM_FILE();
    int N, C, M, no_of_chocolates, no_test, wrappers_worth;
    no_test = in();
    while (no_test--) {
        N = in();
        C = in();
        M = in();
        no_of_chocolates = N/C;
        wrappers_worth = no_of_chocolates;
        while (wrappers_worth/M > 0) {
            no_of_chocolates += wrappers_worth/M;
            wrappers_worth = (wrappers_worth/M) + (wrappers_worth % M);
        }
        cout<< no_of_chocolates <<"\n";
    }
    return 0;
}
