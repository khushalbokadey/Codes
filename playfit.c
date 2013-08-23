#include<stdio.h>
int main()
{
    long no_of_test , N ,i ,j,k, curr , prev , max ,prevbig;
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
                prev = curr;
                prevbig=curr;
                i--;
                continue;
            }
            else
            {
                if(curr>prev)
                {
                    if(curr>prevbig)
                    {
                        max = max + curr-prevbig;
                        prevbig = curr;
                    }
                }
                prev = curr;
                if(max==0 && curr<prevbig)
                    prevbig = curr;
            }
            i--;
        }
        if(max==0)
            printf("UNFIT\n");
        else
            printf("%d\n" , max);
        no_of_test--;
    }
    return 0;
}
