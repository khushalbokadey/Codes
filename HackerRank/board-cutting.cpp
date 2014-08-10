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
    long long int T, M, N, rc, cc, i, j, answer;
    int row[1000003], col[1000003];
    cin >> T;
    cin >> M >> N;
    while(T--) {
        for (i=0; i<M-1; i++) {
            cin >> row[i];
        }
        for (i=0; i<N-1; i++) {
            cin >> col[i];
        }
        rc = cc = 1;
        answer = 0;
        sort(row, row+M-1, std::greater<int>());
        sort(col, col+N-1, std::greater<int>());
        i = j = 0;
        while(i<M-1 && j<N-1) {
            if (row[i]*cc >= col[j]*rc) {
                cout << row[i] << " ";
                answer += row[i]*cc;
                i++;
                rc++;
            }
            if (row[i]*cc < col[j]*rc) {
                cout << col[j] << " ";
                answer += col[j]*rc;
                j++;
                cc++;
            }
        }
        while (i<M-1) {
            cout << row[i] << " ";
            answer += row[i]*cc;
            i++;
            rc++;
        }
        while (j<N-1) {
            cout << col[j] << " ";
            answer += col[j]*rc;
            j++;
            cc++;
        }
        cout << answer%1000000007 << "\n";
    }
    return 0;
}
