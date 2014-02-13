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
    freopen("input.txt", "r", stdin);
    #endif
}

int main()
{
    INPUT_FROM_FILE();
    int N, arr[100004], i;
    int max_curr, max_overall;
    N = in();
    for(i=0; i<N; i++) {
        cin >> arr[i];
    }
    max_curr = 0;
    max_curr = 0;
    for (i=0; i<N; i++) {
        max_curr =  max(max_curr + arr[i], 0);
        max_overall = max(max_curr, max_overall);
    }
    cout << max_overall << "\n";
    return 0;
}
