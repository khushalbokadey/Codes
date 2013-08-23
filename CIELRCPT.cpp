#include<math.h>
#include<iostream>

using namespace std;

int main()
{
    int no_of_test ,i ;
    long total , p ;

    cin>>no_of_test;

    while(no_of_test)
    {
        total = 0;
        i=11;
        cin>>p;
        while(i!=0)
        {
            long temp;
            temp = (pow( 2 , i));
            total+= (p/ temp);
            p = p % temp;
            i--;
        }
        total+=p;
        cout<<total<<"\n";
        no_of_test--;
    }

    return 0;
}
