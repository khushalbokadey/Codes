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
    int T, N, answer, val, N_temp;
    cin >> T;
    while (T--) {
        cin >> N;
        N_temp = N;
        val = 0;
        while (N != 1) {
            if (N%3 == 0) {
                N/=3;
                val++;
            } else if (N%2 == 0) {
                N /= 2;
                val++;
            }
            if (N>1 && N%3!=0 && N%2!=0) {
                N -= 1;
                val++;
            }
        }
        answer = min(val, N_temp);
        N = N_temp;
        val = 0;
        while (N!=1) {
            if (N%3 == 0) {
                N/=3;
                val++;
            }
            if (N>1 && N%3!=0) {
                N -= 1;
                val++;
            }
        }
        answer = min(val, answer);
        N = N_temp;
        val = 0;
        while (N!=1) {
            if (N%2 == 0) {
                N/=2;
                val++;
            }
            if (N>1 && N%2!=0) {
                N -= 1;
                val++;
            }
        }
        answer = min(val, answer);
        cout << answer << "\n";
    }
    return 0;
}
