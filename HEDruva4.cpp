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

int getOne (int n) {
    int i;
    int * dp;
    dp= new int[n];
    dp[1] = 0;
    for(i=2; i<=n; i++) {
        dp[i] = 1 + dp[i-1];
        if(i%2==0) dp[i] = min( dp[i] , 1+ dp[i/2] );
        if(i%3==0) dp[i] = min( dp[i] , 1+ dp[i/3] );
    }
    return dp[n];
}

int main()
{
    INPUT_FROM_FILE();
    int t, n;
    int answer;
    cin >> t;
    while (t--) {
        cin >> n;
        answer = getOne(n);
        cout << answer << "\n";
    }
    return 0;
}
