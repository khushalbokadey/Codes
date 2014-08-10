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
int superPower(int Z) {

    int a, b, i;
    double x;
    b = log(Z) + 1;
    for (i=2; i<=b; i++) {
        x = pow(Z, 1.0/i);
        double decimal, intpart;
        decimal = std::modf(x, &intpart);
        if (decimal == 0.0) {
                cout << x << " ";
            return 1;
        }
    }
    return 0;
}
int main()
{
    INPUT_FROM_FILE();
    int Z;
    cin >> Z;
    cout << superPower(Z) << "\n";
    return 0;
}

