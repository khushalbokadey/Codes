#include<stdio.h>

int isprime(long);

int main()
{
    long no_of_test , number , pr , i , sum;
    scanf("%ld" , &no_of_test);
    while(no_of_test!=0)
    {
        scanf("%ld" , &number);
        pr=2;
        sum = 0;
        i=1;
        while(pr<number)
        {
            if(pr==2)
            {
                sum+=pr;
                if(3<number)
                {
                    sum+=3;
                    pr = (6*i) - 1;
                }
                if(pr>=number)
                    break;
            }
            if(isprime(pr))
            {
                sum+=pr;
            }
            pr = (6*i) + 1;
            if(pr<number && isprime(pr))
            {
                sum+=pr;
            }
            i++;
            pr = (6*i) - 1;
        }
        printf("%ld\n" , sum);
        no_of_test--;
    }
    return 0;
}
int isprime(long num)
{
    if(num%2==0 || num%3==0)
        return 0;
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
