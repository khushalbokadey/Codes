#include<iostream>

using namespace std;

int main()
{
    int N , Q , no_of_test;
    int numberarray[100003] , a, p, q;
    int i, j , max;

    cin>>no_of_test;

    while(no_of_test)
    {
        cin>>N>>Q;
        for(i=0;i<N;i++)
        {
            cin>>numberarray[i];
        }
        while(Q)
        {
            cin>>a>>p>>q;
            max = numberarray[p-1]^a;
            for(i=p;i<q;i++)
            {
                int temp = a^numberarray[i];
                if(max<temp)
                {
                    max = temp;
                }
            }
            cout<<max<<"\n";
            Q--;
        }
        no_of_test--;
    }

    return 0;
}
