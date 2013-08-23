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

#define all(v) (v).begin(), (v).end()
#define fe(i,v) for(int i=0 ; i<(v).size(); i++)

using namespace std;

class SupermarketDiscount
{
    public:
    int minAmount(vector<int> goods)
    {
        int x =0 , y=0;
        for(int i=0 ; i<3;i++)
        {
            x+=goods[i];
            y+=goods[i];
            if(goods[i]>=50)
            {
                x-=10;
                y-=goods[i];
            }
        }
        if(y>=50)
            x-=10;
        return x;
    }
};
int main()
{
    SupermarketDiscount obj ;
    vector<int> goods(3);
    goods[0] = 29;
    goods[1] = 48;
    goods[2] = 49;
    int ans = obj.minAmount(goods);
    cout<<ans;
    return 0;
}
