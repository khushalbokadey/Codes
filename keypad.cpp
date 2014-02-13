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
    int freq, fArr[1003], k, arr[53];
    int temp[2600];
    int i,j, a, sum, answer;
    cin >> freq;
    for(i=0; i<freq; i++) {
        cin >> fArr[i];
    }
    cin >> k;
    sum = 0;
    for (i=0; i<k; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    if (freq>sum) {
        cout << "-1";
        return -1;
    }
    sort(fArr, fArr+freq,std::greater<int>());
    a=0;
    for (i=0; i<k; i++) {
        for (j=1; j<=arr[i]; j++) {
            temp[a] = j;
            a++;
        }
    }
    a--;
    sort(temp, temp+sum);
    answer = 0;
    for (i=0; i<freq; i++) {
        answer += (fArr[i] * temp[i]);
    }
    cout << answer << "\n";
    return 0;
}
