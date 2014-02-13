#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 0; i < n; i++)
#define diff(a,b) (b-a)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

int main()
{
    INPUT_FROM_FILE();
    long long N, K, arr[100003], i, j, min, k, fwd_first, fwd_last, bck_first, bck_last;
    long long min_count, count;
    N = in();
    K = in();
    fr(i,N) {
        arr[i] = in();
    }
    sort(arr, arr+N);
    for (k=0; k<=N-K; k++) {
        fwd_first = k;
        fwd_last = k+K-1;
        count = 0;
        for (i=fwd_last; i>=fwd_first; i--) {
            count += (arr[i] * (i + i - fwd_first - fwd_last));
        }
        if (k==0 || count < min_count)
            min_count = count;
        bck_first = N-K-k-1;
        bck_last = bck_first + K;
        count = 0;
        for (i=bck_last; i>=bck_first; i--) {
            count += (arr[i] * (i + i - bck_first - bck_last));
        }
        if (count < min_count)
            min_count = count;
        if (fwd_last == N/2-1 || bck_first == N/2-1)
            break;
    }
    cout << min_count<< "\n";
    return 0;
}
