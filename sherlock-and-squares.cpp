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
    int N, A, B, count;
    double sqrA, sqrB;
    cin >> N;
    while (N--) {
        cin >> A >> B;
        count = 0;
        if (A == B) {
            sqrA = sqrt(A);
            double decimal, intpart;
            decimal = std::modf(sqrA, &intpart);
            if (decimal == 0.0) {
                count++;
            }
        } else {
            sqrA = sqrt(A);
            double decimal, intpart;
            decimal = std::modf(sqrA, &intpart);
            if (decimal == 0.0) {
                count++;
            }
            sqrB = sqrt(B);
            decimal = std::modf(sqrB, &intpart);
            if (decimal == 0.0) {
                count++;
                sqrB -= 1;
            }
            count += (int)sqrB - (int)sqrA;
        }
        cout << count << "\n";
    }
    return 0;
}
