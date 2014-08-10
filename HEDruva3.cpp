#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>
#include<set>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 0; i < n; i++)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

int subset_count( int S[], int m, int n )
{
    int table[n+1];
    memset(table, 0, sizeof(table));
    table[0] = 1;
    for(int i=0; i<m; i++)
        for(int j=S[i]; j<=n; j++)
            table[j] += table[j-S[i]];

    return table[n];
}

int main()
{
    INPUT_FROM_FILE();
    std::set<int> given;
    std::set<int>::iterator it;
    std::set<int>::iterator it1;
    int N, Q, arr[36003];
    int i, j, k, angle, val, arr_size;
    bool flag;
    cin >> N >> Q;
    for (i=0; i<N; i++) {
        cin >> angle;
        arr[i] = angle;
        given.insert(angle);
    }
    for (i=0; i<Q; i++) {
        cin >> angle;
        if (subset_count(arr, N, angle)>0) {
            cout << "YES\n";
            continue;
        }
        flag = false;
        for (it=given.begin(); it!=given.end(); ++it) {
            int temp = *it;
            while (temp <= 360 && temp!=0) {
                if (temp == angle) {
                    flag = true;
                    cout << "YES\n";
                    break;
                }
                temp += temp;
            }
            if (flag)
                break;
            if (*it != 0) {
                for (k=1; k<=36; k++) {
                    val = *it * k;
                    if (val==angle) {
                        flag = true;
                        break;
                    }
                    it1 = given.find((val%360) + angle);
                    if (it1 != given.end()) {
                        flag = true;
                        break;
                    }
                    it1 = given.find(abs(val%360) - angle);
                    if (it1 != given.end()) {
                        flag = true;
                        break;
                    }
                }
                if (flag) {
                    cout << "YES\n";
                    break;
                }
            }
        }
        if (!flag) {
            cout << "NO\n";
        }
    }
    return 0;
}
