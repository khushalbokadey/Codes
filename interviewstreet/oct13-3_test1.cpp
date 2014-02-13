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
    long long N, K, arr[100003], i, j, min, k, first, last;
    long long min_count, count;
    N = in();
    K = in();
    fr(i,N) {
        arr[i] = in();
    }
    sort(arr, arr+N);
    for (k=0; k<=N-K; k++) {
        first = k;
        last = k+K-1;
        count = 0;
        for (i=last; i>=first; i--) {
            count += (arr[i] * (i + i - first - last));
        }
        if (k==0 || count < min_count)
            min_count = count;
    }
    cout << min_count<< "\n";
    return 0;
}
