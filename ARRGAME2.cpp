#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>
#include <iomanip>
#include <set>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 0; i < n; i++)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

int countA[1000000003];

int main()
{
    INPUT_FROM_FILE();
    int T, N, i, j, input;
    set <int> A, B;
    set<int>::iterator it;
    float count, output;
    T = in();
    while (T--) {
        A.clear();
        B.clear();
        N = in();
        count = 0;
        fr(i,N) {
            input = in();
            A.insert(input);
        }
        fr(i,N) {
            input = in();
            B.insert(input);
        }
        for (it=A.begin(); it!=A.end(); ++it) {
            cout << ' ' << *it << " " << A.count(*it) << "\n";
        }
        cout<<"\n";
        /*fr(i,N) {
            fr(j,N) {
                if ( (log(A[i]) / A[i]) > (log(B[j]) / B[j]) ) {
                    count++;
                }
            }
        }*/
        cout.setf(ios::fixed,ios::floatfield);
        output = (float)(count * 1000000)/N;
        //cout<< std::setprecision(6)<< output/1000000 << "\n";
    }
    return 0;
}
