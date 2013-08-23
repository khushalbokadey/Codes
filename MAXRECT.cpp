#include<iostream>

using namespace std;

int main()
{
    long H, W;
    long long i, j, k, arr[302][302], sum;
    int r_size, c_size, r_start, r_end, c_start, c_end;

    cin>>H>>W;

    for(i=0;i<H;i++)
    {
        for(j=0;j<W;j++)
        {
            cin>>arr[i][j];
        }
    }

    sum = arr[0][0];
    r_size = 1;
    c_size = 1;
    r_start = 0;
    r_end = 0;
    c_start = 0;
    c_end = 0;

    for(i=0 ; i<H ; i++)
    {
        for(j=i ; j<H ; j++)
        {
            for(k=0 ; k<W ; k++)
            {

            }
        }
    }

    return 0;
}
