#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int count=0;
void chkciel(int);
int main()
{
    long no_of_test , len , i , price , j;
    char str[1002];
    scanf("%d" , &no_of_test);
    cin.getline(str , 100);
    while(no_of_test!=0)
    {
        cin.getline(str , 100);
        for(i=0;i<strlen(str);i++)
        {
            if(str[i]==' ' && (str[i+1]>='0' && str[i+1]<='9'))
            {
                price=0;
                for(j=i+1;j<strlen(str);j++)
                {
                    if(str[j]<'0' || str[j]>'9')
                        break;
                    price = (price*10) + (str[j]-48);
                }
            }
        }
        chkciel(price);
        no_of_test--;
    }
    printf("%d\n" , count);
    return 0;
}
void chkciel(int num)
{
    long temp , c3 , c5 ,c8 , num1;
    c3=0;
    c5=0;
    c8=0;
    bool flag = true;
    while(num!=0)
    {
        temp = num%10;
        if(temp==8)
            c8++;
        if(temp==5)
            c5++;
        if(temp==3)
            c3++;
        if(temp==0 || temp==1 || temp==2 || temp==4 || temp==6 || temp==7 || temp==9)
        {
            flag = false;
            break;
        }
        num/=10;
    }
    if((c8>=c5)&&(c5>=c3) && flag==true)
    {
        count++;
    }
}
