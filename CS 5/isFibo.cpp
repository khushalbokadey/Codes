#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>
#include <stdint.h>

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
    unsigned long long fibo[] = {0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233,
                                377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711,
                                28657, 46368, 75025, 121393, 196418, 317811, 514229,
                                832040, 1346269, 2178309, 3524578, 5702887, 9227465,
                                14930352, 24157817, 39088169, 63245986, 102334155, 165580141,
                                267914296, 433494437, 701408733, 1134903170, 1836311903,
                                2971215073, 4807526976, 7778742049, 12586269025, 20365011074,
                                32951280099, 53316291173, 86267571272, 139583862445};
    unsigned long long T, N, i,j;
    bool flag;
    T = in();
    while (T--) {
        cin >> N;
        flag = false;
        for (i=0; i< 55; i++) {
            if (N == fibo[i]) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "IsFibo\n";
        } else {
            cout << "IsNotFibo\n";
        }
    }
    return 0;
}
