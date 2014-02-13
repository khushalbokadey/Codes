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
    int T, N, i, j, k, min_val;
    int W[100003];
    N = in();
    T = in();
    fr(i,N) {
        W[i] = in();
    }
    while (T--) {
        i = in();
        j = in();
        min_val = 4;
        for (k = i; k <= j; k++) {
            if (W[k] < min_val) {
                min_val = W[k];
            }
            if (min_val == 1)
                break;
        }
        cout << min_val << "\n";
    }
    return 0;
}
