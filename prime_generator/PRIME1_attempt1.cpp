#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;

int main()
{
    int no_of_test;
    bool boolnumbers[1000000];
    long long n, m, sqroot, i ;
    cin>>no_of_test;
    while(no_of_test)
    {
        cin>>m>>n;
        sqroot = sqrt(n);
        fill(boolnumbers, boolnumbers+sqroot, false);

        for (long long x = 1; x <= sqroot; x++)
        {
            for (long long y = 1; y <= sqroot; y++)
            {
                long long num = (4*x*x)+(y*y);
                if (num <= n && (num % 12 == 1 || num % 12 == 5))
                {
                    boolnumbers[num] = true;
                }
                num = (3*x*x)+(y*y);
                if (num <= n && num % 12 == 7)
                {
                    boolnumbers[num] = true;
                }
                num = (3*x*x)-(y*y);
                if (x > y && num <= n && num % 12 == 11)
                {
                    boolnumbers[num] = true;
                }
            }
        }
        for(i=0;i<sqroot;i++)
        {
            if(boolnumbers[i])
            {
                cout<<i<<"\n";
            }
        }
        no_of_test--;
    }
    return 0;
}
