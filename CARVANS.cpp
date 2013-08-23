#include<iostream>
using namespace std;

int main()
{
    int no_of_test, N , speed1, speed2 , count;
    cin>>no_of_test;
    while(no_of_test)
    {
        cin>>N;
        count=1;
        cin>>speed1;
        N--;
        while(N)
        {
            cin>>speed2;
            if(speed1>=speed2)
            {
                speed1 = speed2;
                count++;
            }
            N--;
        }
        cout<<count<<"\n";
        no_of_test--;
    }
    return 0;
}
