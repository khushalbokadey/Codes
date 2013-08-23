#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int count=0;
int main()
{
    long long num , num1=8;
    long long temp , c3 , c5 ,c8;
    bool flag = true;
    while(count!=50000)
    {
        c3=0;
        c5=0;
        c8=0;
        num= num1;
        flag= true;
        while(num!=0)
        {
            temp = num%10;
            if(temp==8)
                c8++;
            else if(temp==5)
                c5++;
            else if(temp==3)
                c3++;
            else
            {
                flag = false;
                break;
            }
            num/=10;
        }
        if((c8>=c5)&&(c5>=c3) && flag==true)
        {
            cout<<num1<<" "<<count<<"\n";
            count++;
        }
        num1++;

    }
}
