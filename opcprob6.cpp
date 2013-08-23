#include<list>
#include<vector>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>

using namespace std;

#define ALL(x) (x).begin(),(x).end()
#define FOR(i,a,b) for(int i=(a) ; i<=(b) ;++i)

class IrreducibleNumber
{
    public :
    int getIrreducible(vector<int>A)
    {
        set<int> s(ALL(A));
        s.insert(A[0] + A[1]);
        s.insert(A[0] + A[2]);
        s.insert(A[1] + A[2]);
        s.insert(A[0] + A[1] + A[2]);
        FOR(i,1,10000) if(!s.count(i)) return i;
    }
};

int main()
{
    IrreducibleNumber obj;
    vector<int> value(2);
    value[0] = 1;
    value[1] = 1;
    int ans = obj.getIrreducible(value);
    cout<<ans;
    return 0;
}
