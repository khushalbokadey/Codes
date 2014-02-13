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
long long int numbers[1003];

int main()
{
    INPUT_FROM_FILE();
    int i, j, k;
    int T, N;
    bool flag;
    numbers[0] = 0;
    numbers[1] = 9;
    j = 0;
    i = 2;
    while (i<500) {
        for (k = pow(2,j); k< pow(2,j+1); k++) {
            numbers[i++] = numbers[k] * 10 + 0;
            numbers[i++] = numbers[k] * 10 + 9;
        }
        j++;
    }
    T = in();
    while (T--) {
        N = in();
        flag = false;
        for (i=1; i<500; i++) {
            if (numbers[i] % N == 0) {
                cout << numbers[i] << "\n";
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "0\n";
        }
    }
    return 0;
}
