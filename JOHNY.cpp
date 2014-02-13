#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>

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
    int T, N, K, element;
    int arr[103], i;
    T = in();
    while (T--) {
        N = in();
        for (i=0; i<N; i++) {
            arr[i] = in();
        }
        K = in();
        element = arr[K-1];
        sort(arr, arr+N);
        vector<int> v(arr,arr+N);
        vector<int>::iterator index;
        index = lower_bound(v.begin(), v.end(), element);
        cout << index+1 - v.begin()<< "\n";
    }
    return 0;
}
