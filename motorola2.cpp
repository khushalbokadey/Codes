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

int maxNumber(int N) {

    string str = std::to_string(N);
    int i, index, j;
    char max;
    for(j=0; j<str.length()-1; j++) {
        index = j;
        max = str.at(index);
        for (i=j+1; i<str.length(); i++) {
            if (str.at(i) > max) {
                max = str.at(i);
                index = i;
            }
        }
        if (index != j) {
            str.at(index) = str.at(j);
            str.at(j) = max;
            break;
        }
    }
    return  atoi(str.c_str());
}

int main()
{
    //INPUT_FROM_FILE();
    cout << maxNumber(123) << "\n";
    cout << maxNumber(1200) << "\n";
    cout << maxNumber(423) << "\n";
    return 0;
}
