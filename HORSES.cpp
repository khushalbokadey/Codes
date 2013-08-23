#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int no_of_test , N , i , j , min_diff;
    long S[5002];

    cin>>no_of_test;

    while(no_of_test)
    {

        cin>>N;

        for(i=0;i<N;i++)
        {
            cin>>S[i];
        }

        sort(S , S+N);
        min_diff = S[1] - S[0];
        for(i=0;i<N-1;i++)
        {
            if(S[i+1]-S[i]<min_diff)
            {
                min_diff = S[i+1] - S[i];
            }
        }
        cout<<min_diff<<"\n";
        no_of_test--;
    }

    return 0;
}
