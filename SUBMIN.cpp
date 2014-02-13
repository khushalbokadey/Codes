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
    int N, Q, K, i, j, curr_min, ans, left_count, right_count;
    int arr[53];
    N = in();
    for (i=0; i<N; i++) {
        arr[i] = in();
    }
    Q = in();
    while (Q--) {
        K = in();
        ans = 0;
        for (i=0; i<N; i++) {
            if (arr[i] == K) {
                ans++;
                left_count = 0;
                right_count = 0;
                j = i-1;
                while (j>=0 && (K == min(K, arr[j])) && arr[j] != K) {
                    j--;
                    left_count++;
                    ans++;
                }
                j = i+1;
                while (j<N && (K == min(K, arr[j]))) {
                    j++;
                    right_count++;
                    ans++;
                }
                ans += (left_count * right_count);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
