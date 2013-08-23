#include<stdio.h>
#include<math.h>
int main()
{
    long no_of_test , diagonal , i , j ,k , sqr;
    bool flag;
    scanf("%d" , &no_of_test);
    while(no_of_test!=0)
    {
        scanf("%d",&diagonal);
        sqr = sqrt(diagonal);
        flag = false;
        for(i=1;i<=sqr;i++)
        {
            for(j=sqr;j>=sqr/2;j--)
            {
                if((i*i)+(j*j)==diagonal)
                {
                    //printf("%d %d" , i , j);
                    flag = true;
                    break;
                }
            }
            /*k = diagonal - (i*i);
            j = sqrt(k);
            if((i*i)+(j*j)==diagonal)
            {
                flag = true;
                break;
            }*/
            if(flag==true)
            {
                break;
            }
        }
        if(flag==true)
            printf("YES\n");
        else
            printf("NO\n");
        no_of_test--;
    }
    return 0;
}
