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
    char arr[100003];
    int N;
    std::size_t pos, pos1;
    N = in();
    while(N--) {
        cin>>arr;
        string str(arr);
        pos = str.find("010");
        pos1 = str.find("101");
        if (pos == std::string::npos && pos1 == std::string::npos) {
            cout << "Bad\n";
        } else {
            cout << "Good\n";
        }
    }
    return 0;
}
