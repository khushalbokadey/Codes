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

string checkValidString(string S) {

    int i;
    for (i=0; i<S.length(); i++) {
        if (! (S.at(i) == '1' || S.at(i) == '2')) {
            return "Invalid\n";
        } else if (i<=S.length() - 3 && S.at(i) == '1' && S.at(i+1) == '2' && S.at(i+2) == '2') {
            i+=2;
        } else if (i<=S.length() - 2 && S.at(i) == '1' && S.at(i+1) == '2') {
            i+=1;
        } else if (i<=S.length() - 1 && S.at(i) == '1') {
            i+=0;
        } else {
            return "Invalid\n";
        }
    }
    return "Valid\n";

}

int main()
{
    //INPUT_FROM_FILE();
    cout << checkValidString("1221");
    cout << checkValidString("2");
    cout << checkValidString("12122");
    return 0;
}
