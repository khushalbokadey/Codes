#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<algorithm>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 0; i < n; i++)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("ip.txt", "r", stdin);
    #endif
}

int main()
{
    INPUT_FROM_FILE();
    int no_of_test, i , n;

    long long int num[3], mul, total, mods;

    no_of_test = in();

    while(no_of_test--)
    {
        mods = 1000000007;
        cin>>num[0]>>num[1]>>num[2];
        //cout<<num[0]<<" "<<num[1]<<" "<<num[2]<<endl;
        sort(num,num+3);

        num[0] = num[0]%mods;
        num[1] = (num[1]-1)%mods;
        num[2] = (num[2]-2)%mods;

        mul = num[0] * num[1];
        mul = mul%mods;

        mul = mul * num[2];
        total = mul%mods;

        cout<<total<<"\n";
    }

    return 0;
}
