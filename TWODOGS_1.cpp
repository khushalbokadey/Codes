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
    int N, K, arr[500003];
    int i, j, answer;
    const int MAX = 1000000;
    bool map_arr[1000003];
    cin>> N >> K;
    for (i=0; i<N; i++) {
        cin >> arr[i];
    }
    answer = -1;
    //Both from lefts
    for (i=0; i<=K; i++) {
        map_arr[i] = false;
    }
    for (i=0; i<N; i++) {
        j = K - arr[i];
        if (j>0 && map_arr[j] && arr[i] != j) {
            answer = i+1;
            break;
        }
        map_arr[arr[i]] = true;
    }
    // Right
    for (i=0; i<=K; i++) {
        map_arr[i] = false;
    }
    for (i=N-1; i>=0; i--) {
        j = K - arr[i];
        if (j>0 && map_arr[j] && arr[i] != j) {
            answer = min(answer, N-i);
            break;
        }
        map_arr[arr[i]] = true;
    }
    //Both
    for (i=0; i<=K; i++) {
        map_arr[i] = false;
    }
    for (i=0; i<N/2; i++) {
        j = K - arr[i];
        if (j>0 && map_arr[j] && arr[i] != j) {
            answer = min(answer, i+1);
            break;
        }
        map_arr[arr[i]] = true;

        j = K - arr[N-i-1];
        if (j>0 && map_arr[j] && arr[N-i-1] != j) {
            answer = min(answer, i+1);
            break;
        }
        map_arr[arr[N-i-1]] = true;
    }
    cout << answer << "\n";
    return 0;
}
