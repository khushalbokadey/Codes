#include<iostream>
#include<math.h>
#include <set>
using namespace std;

int main()
{
    long long N , K, sqrtN , count=0, sqrtK;
    long long Q,i,j;
    int T;
    cin>>N>>Q;
    sqrtN = sqrt(N);

    set<long long> divisorofN;
    set<long long>::iterator iter;

    divisorofN.clear();
    for(i=1;i<=sqrtN+1;i++)
    {
        if(N%i==0)
        {
            divisorofN.insert(i);
            divisorofN.insert(N/i);
        }
    }
    /*for(iter=divisorofN.begin();iter!=divisorofN.end();iter++)
    {
        cout<<*iter<<"\n";
        count++;
    }
    cout<<count<<"\n";*/
    for(i=0;i<Q;i++)
    {
        count=0;
        cin>>T>>K;

        if(T==1)
        {
            set<long long> divisorofK;
            sqrtK = sqrt(K);
            for(j=1;j<=sqrtK+1;j++)
            {
                if(K%j==0)
                {
                    divisorofK.insert(j);
                    divisorofK.insert(K/j);
                }
            }

            if(*divisorofK.end()<*divisorofN.end())
            {
                for(iter=divisorofK.begin();iter!=divisorofK.end();iter++)
                {

                    //ret = divisorofN.equal_range(*iter);
                    if(*iter==*divisorofN.find(*iter) && divisorofN.count(*iter)!=0)
                    {
                        //cout<<*iter;
                        count++;
                    }
                }
            }
            else
            {
                for(iter=divisorofN.begin();iter!=divisorofN.end();iter++)
                {
                    //ret = divisorofK.equal_range(*iter);
                    if(*iter==*divisorofK.find(*iter) && divisorofK.count(*iter)!=0)
                    {
                        count++;
                    }
                }
            }

        }
        else if(T==2)
        {
            for(iter=divisorofN.begin();iter!=divisorofN.end();iter++)
            {
                if(*iter%K==0)
                {
                    count++;
                }
            }
        }
        else if(T==3)
        {
            for(iter=divisorofN.begin();iter!=divisorofN.end();iter++)
            {
                if(*iter%K!=0)
                {
                    count++;
                }
            }
        }
        cout<<count<<"\n";
    }
    return 0;

}
