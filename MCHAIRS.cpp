#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 0; i <= n; i+=33)
#define mod(answer, mVal) (answer % mVal)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

int main()
{
    INPUT_FROM_FILE();
    long long int T, N, i, k, j, index;
    long long int answer;
    long long int arr[2][23] = { {0, 29, 58, 116, 232, 464, 928, 1856, 3712, 7424, 14848, 29696, 59392, 118784, 237568, 475136, 950272, 1900544, 3801088, 7602176, 15204352, 30408704, 60817408},
    {1, 536870912, 134099126, 1468085858, 1372663674, 729739440, 563876078, 1114968488, 530923104, 387839436, 1063862114, 1681930880, 1295334152, 1592325240, 192560036, 1204765734, 1660335522, 318014302, 1568615546, 1928995132, 1232542080, 336606624, 527549250 } };
    const long long int mVal = 1000000007;
    T = in();
    while (T--) {
        cin >> N;
        for (i=22; i>=0; i--) {
            if (arr[0][i] <= N) {
                index = i;
                break;
            }
        }
        answer = arr[1][index];
        i = arr[0][index];
        j = N - 29;
        for(k = i; k <= j; k+=29) {
            answer = mod(answer,mVal) << 29;
        }
        while (k!=N) {
            answer = mod(answer,mVal) << 1;
            k++;
        }
        answer = (answer % mVal);
        cout << answer <<"\n";
    }
    return 0;
}
