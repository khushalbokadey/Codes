#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 0; i < n; i++)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

int gcd (int a, int b) {
    if(a > b) {
        if(a % b == 0) {
            return b;
        }
        else {
            b = a % b;
            gcd(a, b);
        }
    } else {
        if(b % a == 0) {
            return a;
        }
        else {
            a = b % a;
            gcd(a, b);
        }
    }
    return 1;
}

int gcdN (vector<int> arr) {
    //sort(arr, arr+arr.size());
    int result = arr.at(0);
    if (result != 1) {
        for(int i = 1; i < arr.size(); i++){
            result = gcd(result, arr.at(i));
        }
    }
    return result;
}

int values [503][100000];
int T, K, arrK[503];

int calculateGCD (int indexI, int indexJ) {
    int i, result;
    while (indexI <= K-2) {
        for (i=0; i< arrK[indexI+1]; i++) {
            result = calculateGCD(indexI+1, i);
        }
    }
    if (indexI == K-1) {
        return values[indexI][indexJ];
    } else {
        return gcd(values[indexI][indexJ], result);
    }
}

int main()
{
    INPUT_FROM_FILE();
    int i,j;
    long long int sum;
    T = in();
    while (T--) {
        K = in();
        sum = 0;
        for (i=0; i<K; i++) {
            arrK[i] = in();
        }
        for (i=0; i<K; i++) {
            for (j=1; j<=arrK[i]; j++) {
                values[i][j-1] = j;
            }
        }
//        for (i=0; i<K; i++) {
//            for (j=1; j<=arrK[i]; j++) {
//                cout << values[i][j-1] << " ";
//            }
//            cout << "\n";
//        }
        for (i=0; i<arrK[0]; i++) {
            sum = sum + calculateGCD(0, i);
        }
        cout << sum << "\n";
    }
    return 0;
}
