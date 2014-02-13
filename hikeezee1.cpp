#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>
#include<set>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 0; i < n; i++)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

string checkPattern(string input) {

    set<string> pattern_set;
    set<string>::iterator it;
    int i, len;
    string temp;
    len = input.length();
    for (i=0; i<len-2; i++) {
        temp = input.substr(i,3);
        it = pattern_set.find(temp);
        if (it == pattern_set.end()) {
            pattern_set.insert(temp);
        } else {
            return temp;
        }
    }
    return "";
}

int main()
{
    //INPUT_FROM_FILE();
    string answer = checkPattern("abhcfrtfbfhkwpbhcfgrtfdf");
    cout << answer << "\n";
    return 0;
}
