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
    int T, N, i, answer;
    T = in();
    while(T--) {
        N = in();
        answer = 1;
        for (i=0; i<N; i++) {
            if(i%2 == 0)
                answer *= 2;
            else
                answer += 1;
        }
        cout << answer << "\n";
    }
    return 0;
}
