#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>
#include<limits.h>

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
    long long int N, K, arr[100003], aMAX;
    int i;
    cin >> N >> K;
    aMAX = LLONG_MIN;
    for (i=0; i<N; i++) {
        cin >> arr[i];
        if (arr[i] > aMAX)
            aMAX = arr[i];
    }
    for (i=0; i<N; i++) {
        arr[i] = aMAX - arr[i];
    }
    if (K%2 == 1) {
        for (i=0; i<N; i++)
            cout << arr[i] << " ";
    } else {
        aMAX = LLONG_MIN;
        for (i=0; i<N; i++) {
            if (arr[i] > aMAX)
                aMAX = arr[i];
        }
        for (i=0; i<N; i++) {
            arr[i] = aMAX - arr[i];
            cout << arr[i] << " ";
        }
    }
    cout << endl;
    return 0;
}
