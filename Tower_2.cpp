#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

#define INT(c)  ((int)((c) - '0'))
#define CHAR(i) ((char)(i + int('0')))

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

int main()
{
    INPUT_FROM_FILE();
    int r, c;
    int i;
    cin >> c >> r;
    int** arr = new int*[r];
    for(i = 0; i < r; ++i)
        arr[i] = new int[c];
    for (i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cin >> arr[i][j];
        }
    }
    for (i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cout<< arr[i][j];
        }
    }
    return 0;
}
