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

int main()
{
    INPUT_FROM_FILE();
    std::set<string> passSet;
    std::set<string>::iterator it;
    int N, i, j, len;
    string str[103];
    cin >> N;
    for (i=0; i<N; i++) {
        cin >> str[i];
        string temp;
        temp = str[i];
        reverse(temp.begin(), temp.end());
        passSet.insert(temp);
        it = passSet.find(str[i]);
        if (it != passSet.end()) {
            string answer = *it;
            len = answer.length();
            cout << len << " " << answer.at(len/2) << "\n";
            break;
        }
    }
    return 0;
}
