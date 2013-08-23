#include<stdio.h>
int main()
{
    long n , k , num , count=0;
    scanf("%ld %ld",&n,&k);
    while(n>=1)
    {
        scanf("%ld",&num);
        if((num%k)==0)
        {
            count++;
        }
        n--;
    }
    printf("%ld",count);
    return 0;
}
