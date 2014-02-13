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
    long long int no_of_test, i, j, n;
    long long int a[100003], answer;
    no_of_test = in();
    while(no_of_test--) {
        n = in();
        answer = 0;
        fr(i, n) {
            a[i] = in();
        }
        answer = (n * (n-1)) / 2;
        cout << answer << "\n";
    }
    return 0;
}
