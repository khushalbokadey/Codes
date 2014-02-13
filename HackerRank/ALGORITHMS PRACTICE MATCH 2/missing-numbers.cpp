#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>
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

int main()
{
    INPUT_FROM_FILE();
    int A[1000003], B[1000003], i;
    map <int, int> Alist;
    map <int, int> Blist;
    map<int,int>::iterator it;
    map<int,int>::iterator itA;
    int n, m;
    n = in();
    fr(i,n) {
        A[i] = in();
        it = Alist.find(A[i]);
        if (it == Alist.end()) {
            Alist.insert(std::pair<int,int>(A[i], 1) );
        } else {
            it->second++;
        }
    }
    m = in();
    fr(i,m) {
        B[i] = in();
        it = Blist.find(B[i]);
        if (it == Blist.end()) {
            Blist.insert(std::pair<int,int>(B[i], 1) );
        } else {
            it->second++;
        }
    }
    for (it=Blist.begin(); it!=Blist.end(); ++it) {
        itA = Alist.find(it->first);
        if (itA == Alist.end() || itA->second < it->second) {
            cout << it->first << " ";
        }
    }
    cout << endl;
    return 0;
}
