#include<iostream>
#include<vector>
using namespace std;
int dr(int x)
{
        return(x>0?x:-x);
}
class GrabbingTaxi
{
    int minTime(vector <int>,vector <int> , int ,int ,int ,int);
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
