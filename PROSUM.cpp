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
    int T, N, arr[100003];
    int i, j, cnt2;
    long long int answer;
    cin >> T;
    while (T--) {
        cin >> N;
        cnt2 = 0;
        for (i=0; i<N; i++) {
            arr[i] = in();
            if (arr[i] == 2){
                cnt2++;
            }
        }
        sort(arr, arr+N);
        answer = (N * (N-1))/2;
        for (i=0; i<N-1; i++) {
            if (arr[i] == 0) {
                answer -= (N-1-i);
            }
            else if (arr[i] == 1) {
                answer -= (N-1-i);
            }
            if (arr[i] > 2)
                break;
        }
        answer -= (cnt2 * (cnt2-1))/2;
        cout << answer << "\n";
    }
    return 0;
}
