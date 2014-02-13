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
    int T, lenA, lenB, answer, i;
    string A, B;
    int arr[3][65];
    cin >> T;
    while (T--) {
        cin >> A;
        cin >> B;
        lenA = A.size();
        lenB = B.size();
        answer = 0;
        for (i=0; i<= 62; i++) {
            arr[1][i] = 0;
            arr[2][i] = 0;
        }
        for (i=0; i<= lenA; i++) {
            if (A[i]>='A' && A[i] <= 'Z') {
                arr[1][A[i] - 65]++;
            } else if (A[i] >= 'a' && A[i] <= 'z') {
                arr[1][A[i] - 71]++;
            } else if (A[i] >= '0' && A[i] <= '9') {
                arr[1][A[i] + 4]++;
            }
        }
        for (i=0; i<= lenB; i++) {
            if (B[i]>='A' && B[i] <= 'Z') {
                arr[2][B[i] - 65]++;;
            } else if (B[i] >= 'a' && B[i] <= 'z') {
                arr[2][B[i] - 71]++;
            } else if (B[i] >= '0' && B[i] <= '9') {
                arr[2][B[i] + 4]++;
            }
        }
        for (i=0; i<= 62; i++) {
            if (arr[1][i] > 0 && arr[2][i] > 0 && arr[1][i] == arr[2][i]) {
                answer += arr[1][i];
            } else if (arr[1][i] > 0 && arr[2][i] > 0){
                answer += (arr[1][i] < arr[2][i] ? arr[1][i] : arr[2][i]);
            }
        }
        cout << answer << "\n";
    }
    return 0;
}
