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
    int t, i, N, arr[50003], j, currmax, max_index, max_num;
    long long int answer;
    t = in();
    while (t--) {
        N = in();
        answer = 0;
        max_num = 0;
        fr(i,N) {
            arr[i] = in();
            if (arr[i] > max_num) {
                max_num = arr[i];
                max_index = i;
            }
        }
        for (i=0; i<=max_index; i++) {
            answer += (arr[max_index] - arr[i]);
        }
        for (i=max_index+1; i<N; i++) {
            currmax = 0;
            for (j=i+1; j<N; j++) {
                if (arr[j] - arr[i] > currmax)
                    currmax = arr[j] - arr[i];
            }
            answer += currmax;
        }
        cout << answer << "\n";
    }
    return 0;
}
