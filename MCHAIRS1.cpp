#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 0; i <= n; i+=33)
#define mod(answer, mVal) (answer % mVal)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

int main()
{
    INPUT_FROM_FILE();
    int T, N, i, k, j;
    long long int answer;
    const int mVal = 1000000007;
    T = in();
    while (T--) {
        N = in();
        answer = 1;
        j = N - 33;
        fr(i,j) {
            answer = mod(answer,mVal) << 33;
        }
        while (i!=N) {
            answer = mod(answer,mVal) << 1;
            i++;
        }
        //answer = (answer % mVal) - 1;
        cout << answer <<"\n";
    }
    return 0;
}
