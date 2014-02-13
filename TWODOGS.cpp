#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>
#include<set>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 0; i < n; i++)
#define MAX 13

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

int main()
{
    INPUT_FROM_FILE();
    int N, K, i, j, answer;
    int arr[500003];
    bool map_arr[MAX] = {0};
    cin >> N >> K;
    for (i=0; i<N; i++) {
        cin >> arr[i];
    }
    answer = -1;
    for (i=0; i<N; i++) {
        j = K - arr[i];
        if(j > 0 && map_arr[j] == 1) {
            answer = i+1;
            break;
        }
        map_arr[arr[i]] = 1;
    }

    for (i=0; i<MAX; i++) {
        map_arr[i] = 0;
    }
    for (i=N-1; i>=0; i--) {
        j = K - arr[i];
        if(j > 0 && map_arr[j] == 1) {
            answer = min(answer, N-i);
            if (answer < 0)
                answer = N-i;
            break;
        }
        map_arr[arr[i]] = 1;
    }

    for (i=0; i<MAX; i++) {
        map_arr[i] = 0;
    }
    for (i=0; i<N/2; i++) {
        j = K - arr[i];
        if(j > 0 && map_arr[j] == 1) {
            answer = min(answer, i+1);
            break;
        }
        map_arr[arr[i]] = 1;

        j = K - arr[N-(i+1)];
        if (j > 0 && map_arr[j] == 1) {
            answer = min(answer, i+1);
            break;
        }
        map_arr[arr[N-(i+1)]] = 1;
    }
    cout << answer << "\n";
    return 0;
}
