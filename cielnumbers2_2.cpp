#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    long no_of_test , i , c3,c5,c8 , count;
    char str[1002];
    bool flag=true;
    scanf("%d" , &no_of_test);
    count=0;
    cin.getline(str , 100);
    while(no_of_test!=0)
    {
        cin.getline(str , 100);
        c3=0;
        c5=0;
        c8=0;
        flag = true;
        i = strlen(str)-1;
        do
        {
            cout<<str[i];
            if(str[i]=='8')
                c8++;
            else if(str[i]=='5')
                c5++;
            else if(str[i]=='3')
                c3++;
            else
            {
                if(str[i]!=' ')
                    flag = false;
                break;
            }
            i--;
        }while(str[i]!=' ');
        if((c8>=c5)&&(c5>=c3) && flag==true)
        {
            count++;
            cout<<c8<<" "<<c5<<" "<<c3<<" "<<flag<<"\n";
        }
        no_of_test--;
    }
    printf("%d\n" , count);
    return 0;
}
