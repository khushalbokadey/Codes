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
    int arr1[50] = {0};
    int arr2[50] = {0};
    int i, answer = 0;
    string str1, str2;
    cin >> str1 >> str2;
    for (i=0; i<str1.length(); i++) {
        arr1[str1.at(i)-97]++;
    }
    for (i=0; i<str2.length(); i++) {
        arr2[str2.at(i)-97]++;
    }
    for (i=0; i<26; i++) {
        answer += (abs(arr1[i]-arr2[i]));
    }
    cout << answer << "\n";
    return 0;
}
