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
    int T, X, Y;
    int sqrtX, sqrtY;
    cin >> T;
    while (T--) {
        cin >> X >> Y;
        sqrtX = sqrt(X);
        sqrtY = sqrt(Y);
    }
    return 0;
}
