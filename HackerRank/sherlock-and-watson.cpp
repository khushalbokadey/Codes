#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;
void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}
int main()
{
    INPUT_FROM_FILE();
    int N, K, Q, i, x;
    int arr[100004];
    cin >> N >> K >> Q;
    for(i=0; i<N; i++) {
        cin >> arr[i];
    }
    while (Q--) {
        cin >> x;
        cout << arr[(N-(K%N)+x)%N] << "\n";
    }
    return 0;
}
