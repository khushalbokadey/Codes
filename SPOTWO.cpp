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
    int T, N, c, k, i, answer;
    long long int arr[23] = {2, 1024, 976371285, 688423210, 905611805, 607723520, 235042059, 255718402, 494499948, 140625001, 291251492, 25600497, 959366170, 836339738, 621966918, 264444359, 271283348, 952065854, 719476260, 28918236, 855473248, 741583475};
    const long long int mVal = 1000000007;
    T = in();
//    long long int test = 741583475;
//    for (int i=0; i< 9; i++) {
//        test = ((test % mVal) * (741583475 % mVal)) % mVal;
//    }
//    cout << test << "\n";
    while (T--) {
        N = in();
        char binary[31] = "";
        for (c = 31; c >= 0; c--) {
            k = N >> c;
            if (k & 1)
              strncat(binary, "1", c-31);
            else
              strncat(binary, "0", c-31);
        }
        answer = 1;
        for (i=31; i>=10; i--) {
            if (binary[i] == '1') {
                answer = ((answer % mVal) * (arr[31-i-1] % mVal)) % mVal;
            }
        }
        answer = ((answer % mVal) * (answer % mVal)) % mVal;
        cout << answer << "\n";
    }
    return 0;
}
