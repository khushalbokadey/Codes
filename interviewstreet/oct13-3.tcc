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
    int total_arr[100003];
    N = in();
    K = in();
    fr(i,N) {
        arr[i] = in();
    }
    sort(arr, arr+N);
    total_arr[0] = arr[0] + arr[1];
    for (i=1; i<N-1; i++) {
        total_arr[i] = total_arr[i-1] + arr[i+1];
    }
    fr(i,N-1) {
        cout<<total_arr[i] << "\n";
    }
    cout<<min<<"\n";
    return 0;
}
