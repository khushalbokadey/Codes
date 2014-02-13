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
    int N, K, arr[100003], i, j, min;
    N = in();
    K = in();
    fr(i,N) {
        arr[i] = in();
    }
    sort(arr, arr+N);
    min = arr[K-1] - arr[0];
    for (i=1,j=i+K-1; j<N; i++,j++) {
        if ((arr[j]-arr[i]) < min)
            min = arr[j] - arr[i];
    }
    cout<<min<<"\n";
    return 0;
}
