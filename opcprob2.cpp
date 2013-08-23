#include<list>
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

class DivisibleByDigits
{
    public:
    long long getContinuation(int);
};

int main()
{
    DivisibleByDigits obj;
    long long ans = obj.getContinuation(68);
    cout<<ans;
    return 0 ;
}

bool used[10];

bool check (long long x , long long m)
{
    for(int i =0 ; i<10 ;i++)
    {
        used[i] = false;
    }
    while(m)
    {
        used[m%10]=true;
        m/=10;
    }
    for(int i =1 ; i<10 ; i++)
    {
        if(used[i] && (x%i)!= 0 )
            return false;

    }
    return true;
}
long long p10[20];
long long DivisibleByDigits::getContinuation(int n)
{
    if(check(n,n))
        return n;
    p10[0] = 1;
    for(int i =1 ; i<15 ; i++)
    {
        p10[i] = p10[i-1] * 10LL;
    }
    long long A = n;
    for(int i ;; i++)
    {
        for(int j = 0 ; j<p10[i] ; j++)
        {
            if(check(A*p10[i] + j , n))
                return A* p10[i] + j;
        }

    }
}
