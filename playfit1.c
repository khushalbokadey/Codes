#include<stdio.h>
int main()
{
    long no_of_test , N ,i ,j,k, curr , small , max ,prevbig;
    int flag;
    scanf("%ld" , &no_of_test);
    while(no_of_test!=0)
    {
        flag = 0;
        scanf("%ld" , &N);
        i=N;
        max=0;
        while(i!=0)
        {
            scanf("%ld" , &curr);
            if(i==N)
            {
                small = curr;
                i--;
                continue;
            }
            else
            {
                if(curr-small>max)
                    max = curr-small;
                if(curr<small)
                    small = curr;
            }
            i--;
        }
        if(max==0)
            printf("UNFIT\n");
        else
            printf("%ld\n" , max);
        no_of_test--;
    }
    return 0;
}
