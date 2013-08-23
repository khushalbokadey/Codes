#include<stdio.h>
int ispalin(long);
int main()
{
    long no_of_case , num;
    int flag;
    scanf("%ld" , &no_of_case);
    while(no_of_case>=1)
    {
        scanf("%ld" , &num);
        flag = 1;
        while(flag)
        {
            num++;
            if(ispalin(num))
            {
                flag = 0;
            }
        }
        printf("\n%ld" , num);
        no_of_case--;
    }
    return 0;
}
int ispalin(long num)
{
    long rev=0 , tmp;
    tmp = num;
    while(tmp!=0)
    {
        rev*=10;
        rev+= tmp%10;
        tmp/=10;
    }
    if(rev==num)
        return 1;
    else
        return 0;
}
