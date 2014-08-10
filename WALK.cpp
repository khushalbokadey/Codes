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
    int T, N, i, max_ele, index, answer, max_diff;
    int arr [100003];
    cin >> T;
    while (T--) {
        cin >> N;
        max_ele = 0;
        index = 0;
        for (i=0; i<N; i++) {
            cin >> arr[i];
            if (max_ele < arr[i]) {
                max_ele = arr[i];
                index = i;
            }
        }
        answer = max_ele + index;
        max_diff = 0;
        for (i=index; i<N; i++) {
            if (max_ele - (i-index) < arr[i]) {
                int diff = arr[i] - (max_ele - (i-index));
                if (diff > max_diff)
                    max_diff = diff;
            }
        }
        cout << max_ele + index + max_diff<< "\n";
    }
    return 0;
}
