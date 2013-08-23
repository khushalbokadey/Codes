#include<iostream>
#include<vector>
using namespace std;
int dr(int x)
{
        return(x>0?x:-x);
}
class GrabbingTaxi
{
    public:
    int minTime(vector <int>,vector <int> , int ,int ,int ,int);
};
int main()
{
    int ans;
    GrabbingTaxi obj;
    vector<int> tX(2);
    tX[0] = 0;
    tX[1] = -2;
    vector<int> tY(2);
    tY[0] = -2;
    tY[1] = -2;
    ans = obj.minTime(tX,tY,-4,-2,15,3);
    cout<<ans;
    return 0;
}
int minTime(vector <int> x,vector <int> y, int gx,int gy,int wt,int tt)
{
    int ans = (dr(gx)+ dr(gy))*wt;
    int temp;
    int i;
    for(i=0;i<x.size();i++)
    {
        temp = (dr(gx-x[i])+dr(gy-y[i]))*tt + (dr(x[i])+dr(y[i]))*wt;
        if(temp<ans)
            ans=temp;
    }
    return ans;
}
