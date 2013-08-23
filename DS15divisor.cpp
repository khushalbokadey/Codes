#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 0; i < n; i++)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

int main()
{
    INPUT_FROM_FILE();
    int no_of_test, i , n, sqrrt, sum;

    no_of_test = in();

    while(no_of_test--)
    {
        n = in();
        sum = 1;
        sqrrt = ceil(sqrt(n));
        for(i=2; i<sqrrt; i++)
        {
            if(n%i==0)
            {
                sum += i;
                sum += (n/i);
            }
        }
        cout<<sum<<endl;
    }

    return 0;
}
