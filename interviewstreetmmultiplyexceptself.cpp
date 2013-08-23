#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long N;
    long arr[1000];
    long long product;
    int flag , count;
    int i;
    cin>> N;
    product = 1;
    flag = 0;
    count = 0;
    for(i=0;i<N;i++)
    {
        cin>>arr[i];
        if(arr[i]!=0)
        {
            product *= arr[i];
        }
        else
        {
            count++;
            flag = 1;
        }
    }
    long long ans;
    for(i=0;i<N;i++)
    {
        if(count>1)
        {
            cout<<"0"<<"\n";
        }
        else
        {
            if(arr[i]!=0)
            {
                if(flag==0)
                {
                    ans = product/arr[i];
                }
                else
                {
                    ans = 0;
                }
            }
            else
            {
                ans = product;
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
