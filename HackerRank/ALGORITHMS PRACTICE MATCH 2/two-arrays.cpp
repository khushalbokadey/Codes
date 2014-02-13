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
    int t, N;
    long long int K, A[1003], B[1003], i, j, At[1003];
    bool flag;
    t = in();
    while (t--) {
        N = in();
        K = in();
        flag = true;
        fr(i,N) {
            A[i] = in();
        }
        fr(i,N) {
            B[i] = in();
        }
        sort(B, B+N);
        for (i=0; i<N; i++) {
            At[i] = K - A[i];
        }
        sort (At, At+N);
        for (i=0; i< N; i++) {
            if (At[i] > B[i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
