#include<string>
#include<vector>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<numeric>

using namespace std;

#define all(a) a.begin(), a.end()
#define FOR(i,n) for(typeof(n) i=0 ; i<n ; i++)
#define FORE(it,c) for(typeof(c.begin()) it=c.begin(); it!=c.end(); it++)
#define ll long long
#define debug(var) cout<<#var<<"="<<var<<endl

class NumberGuesser
{
    public:
    int guess(string leftover)
    {
        int sum = 0;
        for(int i=0 ;i<3;i++)
        {
            sum+=leftover[i]-'0';
        }
        return 9-(sum%9);
    }
};

int main()
{
    NumberGuesser obj;
    int ans = obj.guess("837");
    cout<<ans;
    return 0;
}
