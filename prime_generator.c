#include<stdio.h>
#include<math.h>
int isprime(long);
int main()
{
    int no_of_case;
    long n , m ;
    scanf("%d" , &no_of_case);
    while(no_of_case>=1)
    {
        scanf("%ld %ld" , &m , &n);
        long i ;
        for(i=m ; i<=n ;i++)
        {
            if(i== 2 || i== 3)
            {
                printf("\n%d" , i);
            }
            else if(isprime(i) && i!=1)
            {
                printf("\n%ld",i);
            }
        }
        no_of_case--;
    }
    return 0;
}
int isprime(long num)
{
    if(num%2==0 || num%3==0)
    {
        return 0;
    }
    else if(num%6!=1 && num%6!=5)
    {
        return 0;
    }
    else
    {
        long sqr_rt , k;
        sqr_rt = sqrt(num);
        k=1;
        while((6*k-1)<= sqr_rt)
        {
            if((num%(6*k-1))==0 || (num%(6*k+1))==0)
            {
                return 0;
            }
            k++;

        }
    }
    return 1;

}
