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

int main()
{
    //INPUT_FROM_FILE();
    int T, N, i, j, dwAns, wAns, x, y;
    bool flag;
    vector<double> Narr, Karr, tempKarr, tempNarr;
    double val;
    vector<double>::iterator it1;
    vector<double>::iterator it2;
    cin >> T;
    for (i=0; i<T; i++) {
        cin >> N;
        tempNarr.clear();
        tempKarr.clear();
        Narr.clear();
        Karr.clear();
        for (j=0; j<N; j++) {
            cin >> val;
            Narr.push_back(val);
            tempNarr.push_back(val);
        }
        for (j=0; j<N; j++) {
            cin >> val;
            Karr.push_back(val);
            tempKarr.push_back(val);
        }
        sort(tempNarr.begin(), tempNarr.end());
        sort(tempKarr.begin(), tempKarr.end());
        x = y = 0;
        for (it1=tempNarr.begin(); it1!=tempNarr.end(); ++it1) {
            y = 0;
            for (it2=tempKarr.begin(); it2!=tempKarr.end(); ++it2) {
                if (*it2 > *it1) {
                    tempKarr.at(y) = -1;
                    tempNarr.at(x) = -1;
                    break;
                }
                y++;
            }
            x++;
        }
        wAns = 0;
        for (it1=tempNarr.begin(); it1!=tempNarr.end(); ++it1) {
            if (*it1 >= 0)
                wAns++;
        }
        tempNarr.clear();
        tempKarr.clear();
        for (it1=Narr.begin(); it1!=Narr.end(); ++it1) {
            tempNarr.push_back(*it1);
        }
        for (it1=Karr.begin(); it1!=Karr.end(); ++it1) {
            tempKarr.push_back(*it1);
        }
        sort(tempNarr.begin(), tempNarr.end());
        sort(tempKarr.begin(), tempKarr.end());
        flag = false;
        x = 0;
        for (it1=tempNarr.begin(); it1!=tempNarr.end(); ++it1) {
            y = 0;
            for (it2=tempKarr.begin(); it2!=tempKarr.end(); ++it2) {
                if (*it2 < *it1) {
                    flag = true;
                    break;
                } else {
                    tempNarr.at(x) = -1;
                    tempKarr.at(y) = -1;
                    break;
                }
                y++;
            }
            x++;
            if (flag)
                break;
        }
        dwAns = 0;
        for (it1=tempNarr.begin(); it1!=tempNarr.end(); ++it1) {
            if (*it1 >= 0)
                dwAns++;
        }
        cout << "Case #" << i+1 << ": " << dwAns << " " << wAns << "\n";
    }
    return 0;
}
