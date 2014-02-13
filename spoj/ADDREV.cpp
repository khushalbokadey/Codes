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

int revnum (int num) {
    int ans = 0;
    while (num!=0) {
        ans = (ans*10) + (num%10);
        num /= 10;
    }
    return ans;
}

int main()
{
    INPUT_FROM_FILE();
    int T, a, b, ans;
    T = in();
    while (T--) {
        a = in();
        b = in();
        ans = revnum (revnum(a) + revnum(b) );
        cout << ans << "\n";
    }
    return 0;
}
