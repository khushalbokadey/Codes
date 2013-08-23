#include<stdio.h>
#include<iostream>
using namespace std;
void display(int , long long);
int main()
{
    long long money , num;
    int len;
    cin>>money;
    num = money;
    len=0;
    cout<<"Rs. ";
    if(money==0)
        cout<<"Zero";
    while(num!=0)
    {
        len++;
        num/=10;
    }
    display(len , money);
    return 0;
}
void display(int len , long long money1)
{
    int count , i;
    long long money , large;
    money = money1;
    count = len;
    if(len>9)
    {
        large= money/1000000000;
        large*=100;
        display(len-9+2,large);
        count = 9;
        money=money%1000000000;
    }
    while(count!=0)
    {
        if(count==1)
        {
            switch(money%10)
            {
                case 1 : cout<<"One ";
                        break;
                case 2 : cout<<"Two ";
                        break;
                case 3 : cout<<"Three ";
                        break;
                case 4 : cout<<"Four ";
                        break;
                case 5 : cout<<"Five ";
                        break;
                case 6 : cout<<"Six ";
                        break;
                case 7 : cout<<"Seven ";
                        break;
                case 8 : cout<<"Eight ";
                        break;
                case 9  : cout<<"Nine ";
                        break;
                case 0 : cout<<"Zero ";
                        break;
                default : break;
            }
            count--;
        }
        else if(count==2)
        {
            if((money/10)==1)
            {
                switch(money%10)
                {
                    case 1 : cout<<"Eleven ";
                            break;
                    case 2  : cout<<"Twelve ";
                            break;
                    case 3 : cout<<"Thirteen ";
                            break;
                    case 4 : cout<<"Fourteen ";
                            break;
                    case 5 : cout<<"Fifteen ";
                            break;
                    case 6 : cout<<"Sixteen ";
                            break;
                    case 7 : cout<<"Seventeen ";
                            break;
                    case 8 : cout<<"Eighteen ";
                            break;
                    case 9  : cout<<"Nineteen ";
                            break;
                    case 0 : cout<<"Ten";
                            break;
                    default : break;
                }
                count--;
            }
            else
            {
                switch(money/10)
                {
                    case 2  : cout<<"Twenty ";
                            break;
                    case 3 : cout<<"Thirty ";
                            break;
                    case 4 : cout<<"Fourty ";
                            break;
                    case 5 : cout<<"Fifty ";
                            break;
                    case 6 : cout<<"Sixty ";
                            break;
                    case 7 : cout<<"Seventy ";
                            break;
                    case 8 : cout<<"Eighty ";
                            break;
                    case 9  : cout<<"Ninety ";
                            break;
                    case 0 : cout<<"";
                            break;
                    default : break;
                }
            }
            count--;
        }
        else if (count==3)
        {
            switch(money/100)
            {
                case 1 : cout<<"One Hundred ";
                        break;
                case 2  : cout<<"Two Hundred ";
                        break;
                case 3 : cout<<"Three Hundred ";
                        break;
                case 4 : cout<<"Four Hundred ";
                        break;
                case 5 : cout<<"Five Hundred ";
                        break;
                case 6 : cout<<"Six Hundred ";
                        break;
                case 7 : cout<<"Seven Hundred ";
                        break;
                case 8 : cout<<"Eight Hundred ";
                        break;
                case 9  : cout<<"Nine Hundred ";
                        break;
                case 0 : cout<<"";
                        break;
                default : break;
            }
            count--;
            money=money%100;
        }
        else if (count==6 || count==7)
        {
            if(count==7)
            {
                if(money/1000000==1)
                {
                    switch((money/100000)-(money/1000000)*10)
                    {
                        case 1 : cout<<"Eleven ";
                                break;
                        case 2  : cout<<"Twelve ";
                                break;
                        case 3 : cout<<"Thirteen ";
                                break;
                        case 4 : cout<<"Fourteen ";
                                break;
                        case 5 : cout<<"Fifteen ";
                                break;
                        case 6 : cout<<"Sixteen ";
                                break;
                        case 7 : cout<<"Seventeen ";
                                break;
                        case 8 : cout<<"Eighteen ";
                                break;
                        case 9  : cout<<"Nineteen ";
                                break;
                        case 0 : cout<<"Ten ";
                                break;
                        default : break;
                    }
                    money = money%100000;
                    count--;
                    count--;
                }
                else
                {
                    switch((money/1000000))
                    {
                        case 2  : cout<<"Twenty ";
                                break;
                        case 3 : cout<<"Thirty ";
                                break;
                        case 4 : cout<<"Fourty ";
                                break;
                        case 5 : cout<<"Fifty ";
                                break;
                        case 6 : cout<<"Sixty ";
                                break;
                        case 7 : cout<<"Seventy ";
                                break;
                        case 8 : cout<<"Eighty ";
                                break;
                        case 9  : cout<<"Ninety ";
                                break;
                        case 0 : cout<<"";
                                break;
                        default : break;
                    }
                    money = money%1000000;
                    count--;
                }
            }
            if(count==6)
            {
                switch(money/100000)
                {
                    case 1 : cout<<"One ";
                            break;
                    case 2  : cout<<"Two ";
                            break;
                    case 3 : cout<<"Three ";
                            break;
                    case 4 : cout<<"Four ";
                            break;
                    case 5 : cout<<"Five ";
                            break;
                    case 6 : cout<<"Six ";
                            break;
                    case 7 : cout<<"Seven ";
                            break;
                    case 8 : cout<<"Eight ";
                            break;
                    case 9  : cout<<"Nine ";
                            break;
                    case 0 : cout<<"";
                            break;
                    default : break;
                }
                money = money%100000;
                count--;
            }
            cout<<"Lac ";
        }
        else if (count==4 || count==5)
        {
            if(count==5)
            {
                if(money/10000==1)
                {
                    switch((money/1000)-(money/10000)*10)
                    {
                        case 1 : cout<<"Eleven ";
                                break;
                        case 2  : cout<<"Twelve ";
                                break;
                        case 3 : cout<<"Thirteen ";
                                break;
                        case 4 : cout<<"Fourteen ";
                                break;
                        case 5 : cout<<"Fifteen ";
                                break;
                        case 6 : cout<<"Sixteen ";
                                break;
                        case 7 : cout<<"Seventeen ";
                                break;
                        case 8 : cout<<"Eighteen ";
                                break;
                        case 9  : cout<<"Nineteen ";
                                break;
                        case 0 : cout<<"Ten ";
                                break;
                        default : break;
                    }
                    money = money%1000;
                    count--;
                    count--;
                }
                else
                {
                    switch((money/10000))
                    {
                        case 2  : cout<<"Twenty ";
                                break;
                        case 3 : cout<<"Thirty ";
                                break;
                        case 4 : cout<<"Fourty ";
                                break;
                        case 5 : cout<<"Fifty ";
                                break;
                        case 6 : cout<<"Sixty ";
                                break;
                        case 7 : cout<<"Seventy ";
                                break;
                        case 8 : cout<<"Eighty ";
                                break;
                        case 9  : cout<<"Ninety ";
                                break;
                        case 0 : cout<<"";
                                break;
                        default : break;
                    }
                    money = money%10000;
                    count--;
                }
            }
            if(count==4)
            {
                switch(money/1000)
                {
                    case 1 : cout<<"One ";
                            break;
                    case 2  : cout<<"Two ";
                            break;
                    case 3 : cout<<"Three ";
                            break;
                    case 4 : cout<<"Four ";
                            break;
                    case 5 : cout<<"Five ";
                            break;
                    case 6 : cout<<"Six ";
                            break;
                    case 7 : cout<<"Seven ";
                            break;
                    case 8 : cout<<"Eight ";
                            break;
                    case 9  : cout<<"Nine ";
                            break;
                    case 0 : cout<<"";
                            break;
                    default : break;
                }
                money = money%1000;
                count--;
            }
            cout<<"Thousand ";
        }
        else if (count==8 || count==9)
        {
            if(count==9)
            {
                if(money/100000000==1)
                {
                    switch((money/10000000)-(money/100000000)*10)
                    {
                        case 1 : cout<<"Eleven ";
                                break;
                        case 2  : cout<<"Twelve ";
                                break;
                        case 3 : cout<<"Thirteen ";
                                break;
                        case 4 : cout<<"Fourteen ";
                                break;
                        case 5 : cout<<"Fifteen ";
                                break;
                        case 6 : cout<<"Sixteen ";
                                break;
                        case 7 : cout<<"Seventeen ";
                                break;
                        case 8 : cout<<"Eighteen ";
                                break;
                        case 9  : cout<<"Nineteen ";
                                break;
                        case 0 : cout<<"Ten ";
                                break;
                        default : break;
                    }
                    money = money%10000000;
                    count--;
                    count--;
                }
                else
                {
                    switch((money/100000000))
                    {
                        case 2  : cout<<"Twenty ";
                                break;
                        case 3 : cout<<"Thirty ";
                                break;
                        case 4 : cout<<"Fourty ";
                                break;
                        case 5 : cout<<"Fifty ";
                                break;
                        case 6 : cout<<"Sixty ";
                                break;
                        case 7 : cout<<"Seventy ";
                                break;
                        case 8 : cout<<"Eighty ";
                                break;
                        case 9  : cout<<"Ninety ";
                                break;
                        case 0 : cout<<"";
                                break;
                        default : break;
                    }
                    money = money%100000000;
                    count--;
                }
            }
            if(count==8)
            {
                switch(money/10000000)
                {
                    case 1 : cout<<"One ";
                            break;
                    case 2  : cout<<"Two ";
                            break;
                    case 3 : cout<<"Three ";
                            break;
                    case 4 : cout<<"Four ";
                            break;
                    case 5 : cout<<"Five ";
                            break;
                    case 6 : cout<<"Six ";
                            break;
                    case 7 : cout<<"Seven ";
                            break;
                    case 8 : cout<<"Eight ";
                            break;
                    case 9  : cout<<"Nine ";
                            break;
                    case 0 : cout<<"";
                            break;
                    default : break;
                }
                money = money%10000000;
                count--;
            }
            cout<<"Crore ";
        }
    }

}
