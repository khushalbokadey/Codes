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
    long long int N, K, arr[100003];
    long long int i, answer;
    N = in();
    K = in();
    fr(i,N) {
        arr[i] = in();
    }
    sort(arr, arr+N);
    answer = 0;
    for (i=0; i< N; i++) {
        if (binary_search(arr+i, arr+N, arr[i]+K))
            answer++;
    }
    cout << answer << "\n";
    return 0;
}
