#include<iostream>
#include<math.h>
using namespace std;
long long int getdollar(long long int );
int main()
{
    long long int no_of_test , number;
    cin>>number;

    cout<<getdollar(number)<<"\n";
    return 0;
}
long long int getdollar(long long int number)
{
    long long int  d2 , d3 , d4 , n2 , n3 , n4;
   // cout<<" "<<number;
        n2 = floor(number/2);
        n3 = floor(number/3);
        n4 = floor(number/4);
        if(n2+n3+n4 > number)
        {
            //cout<<" "<<n2<<" " << n3 << " " <<n4;
            d2 = getdollar(n2);
            d3 = getdollar(n3);
            d4 = getdollar(n4);
            if(d2>n2)
                n2 = d2;
            if(d3>n3)
                n3 = d3;
            if(d4>n4)
                n4 = d4;

            return n2+n3+n4;
        }
        return number;
}
