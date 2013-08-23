#include<stdio.h>
int main()
{
    long no_of_test , N;
    scanf("%ld" , &no_of_test);
    while(no_of_test!=0)
    {
        scanf("%ld" , &N);
        if(N%2==0)
            printf("%ld\n" , N);
        else
            printf("%ld\n" , N-1);
        no_of_test--;
    }
    return 0;
}
