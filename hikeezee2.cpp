#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 0; i < n; i++)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

int t, n;
int ar[20];
map<vector<int>, bool > solutions;
vector<int> v;

void search(int k, int m, int sum, vector<int> v) {
            cout << "asd";
            cout << sum << " " << t << "\n";
    if(sum == t) {
        if(solutions[v] == true) return;
        solutions[v] = true;
        for(int i = 0; i < k; i++)
            printf(i == k - 1? "%d" : "%d+", v[i]);
        printf("\n");
        return;
    }
    if(sum > t || m == n) return;
    for(int i = m; i < n; i++) {
        v.push_back(ar[i]);
        search(k + 1, i + 1, sum + ar[i], v);
        v.pop_back();
    }
}

int main()
{
    INPUT_FROM_FILE();
    string inp;
    int n, i, j, no, len;
    i = 0;
    cin >> inp;
    len = inp.length();
    for (i=0; i<len; i++) {
        if (inp.at(i) == ',') {
            v.push_back(no);
            no = 0;
            continue;
        }
        no = (no*10) + (inp.at(i) - 48);
    }
    v.push_back(no);
    n = v.size();
    t = 211;
    search(0, 0, 0, v);
    return 0;
}
