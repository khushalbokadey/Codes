#include<iostream>
#include<stdio.h>
using namespace std;

bool isprime(long);

int main()
{
    long no_of_test , a , b , i , j ,k , num;
    bool flag;
    scanf("%d" , &no_of_test);
    while(no_of_test!=0)
    {
        scanf("%d %d" , &a , &b);
        flag = true;
        k = a/6;
        k++;
        while((6*k)-1<=b)
        {
            num = (6*k)-1;
            if(num%5!=0 && num%3!=0)
            {
                flag = isprime(num);
            }
            num = (6*k)+1;
            if(num%5!=0 && num%3!=0)
            {
                flag = isprime(num);
            }
            k++;
        }
        no_of_test--;
    }
    return 0;
}

bool isprime(long num)
{
    long chk[3] = {2,7,61};
    long i , k , m , tempnum;
    bool flag;
    k=0;
    tempnum = num;
    tempnum--;
    while(tempnum%2!=0)
    {
        k++;
        tempnum/=2;
    }
    m = tempnum;

    for(i=0;i<3;i++)
    {


    }
}
