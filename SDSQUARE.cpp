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
    //freopen("output.txt", "w", stdout);
    #endif
}

int main()
{
    INPUT_FROM_FILE();
    long long int T, a, b;
    long long int i, sqr, sqrA, sqrB;
    bool flag;
    long long int count[100003], answer;
    count[0] = 0;
    for (i=1; i<=100000; i++) {
        sqr = i * i;
        flag = true;
        while (sqr!=0) {
            if ( sqr%10 != 0 && sqr%10 != 1 && sqr%10 != 4 && sqr%10 != 9 ) {
                flag = false;
                break;
            }
            sqr/=10;
        }
        if (flag)
            count[i] = 1;
        else
            count[i] = 0;
    }
    T = in();
    while (T--) {
        cin >> a >> b;
        sqrA = floor(sqrt(a));
        if (sqrA * sqrA < a)
            sqrA++;
        sqrB = floor(sqrt(b));
        answer = 0;
        for (i=sqrA; i<=sqrB; i++) {
            answer += count[i];
        }
        cout << answer << "\n";
    }
    return 0;
}
