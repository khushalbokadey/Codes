#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>
#include <list>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 1; i <= n; i++)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

int main()
{
    INPUT_FROM_FILE();
    int T, num, num_sqrt;
    int i, factor, overlucky_count;
    list<int> factors_list;
    list<int>::iterator it;

    T = in();
    while (T--) {
        num = in();
        num_sqrt = sqrt(num);
        overlucky_count = 0;
        factors_list.clear();
        it = factors_list.begin();
        fr(i, num_sqrt) {
            if (num % i == 0) {
                factors_list.insert(it, i);
                factors_list.insert(it, num/i);
            }
        }
        for (it = factors_list.begin(); it != factors_list.end(); it++) {
            factor = *it;
            while (factor != 0) {
                if (factor % 10 == 4 || factor % 10 == 7) {
                    overlucky_count++;
                    break;
                }
                factor /= 10;
            }
        }
        cout << overlucky_count << "\n";
    }
    return 0;
}
