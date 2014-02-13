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


long modPow(long a, long x, long p) {
    //calculates a^x mod p in logarithmic time.
    long res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res;
}

long modInverse(long a, long p) {
    return modPow(a, p-2, p);
}

long modBinomial(long n, long k, long p) {

    long numerator = 1;
    for (int i=0; i<k; i++) {
        numerator = (numerator * (n-i) ) % p;
    }

    long denominator = 1;
    for (int i=1; i<=k; i++) {
        denominator = (denominator * i) % p;
    }

    return ( numerator* modInverse(denominator,p) ) % p;
}

int main()
{
    INPUT_FROM_FILE();
    int T, m, n, i;
    long ans;
    T = in();
    while (T--) {
        m = in();
        n = in();
        ans = modBinomial(n+m-2, m-1, 1000000007);
        cout << ans << "\n";
    }
    return 0;
}
