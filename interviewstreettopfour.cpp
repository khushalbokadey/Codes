#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long N , top[4] , i , num , j;
    fill(top,top+4,-2147483647);
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>num;
        for(j=0;j<4;j++)
        {
            if(num>top[j])
            {
                int k;
                for(k=3;k>=j+1;k--)
                {
                    top[k] = top[k-1];
                }
                top[j] = num;
                break;
            }
        }
    }
    for(j=0;j<4;j++)
    {
        cout<<top[j]<<"\n";
    }
    return 0;
}
