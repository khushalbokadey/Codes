#include<stdio.h>
int main()
{
    long long t , n ,  i , final;
    scanf("%i" , &t);
    while(t!=0)
    {
        scanf("%i" , &n);

        //n=n-1;
        i = 2*n -1;
        final = i*i + n-1;
        printf("%i" , final);

        t--;
    }
    return 0;
}
