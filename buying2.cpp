#include<iostream>
#include<set>

using namespace std;

int main()
{
    int no_of_test, N, X;
    int Notes[102];
    int i, j, sum, sweetcount, flag;
    cin>>no_of_test;

    while(no_of_test)
    {
        set<int> myset;
        set<int>::iterator it;

        cin>>N>>X;
        sum=0;
        for(i=0;i<N;i++)
        {
            cin>>Notes[i];
            if(Notes[i]<=X)
            {
                myset.insert(Notes[i]);
            }
            sum+=Notes[i];
        }
        sweetcount = sum/X;
        flag = 1;
        for(it=myset.begin(); it!=myset.end();it++)
        {
            if(sweetcount == ((sum-*it)/X))
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            cout<<sweetcount<<"\n";
        }
        else
        {
            cout<<"-1\n";
        }
        no_of_test--;
    }

    return 0;
}
