#include<stdio.h>
#include<math.h>
int main()
{
    long no_of_test , diagonal , i , j;
    bool flag;
    scanf("%d" , &no_of_test);
    while(no_of_test!=0)
    {
        scanf("%d",&diagonal);
        flag = false;
        for(i=1;i<sqrt(diagonal);i++)
        {
            for(j=1;j<sqrt(diagonal);j++)
            {
                if((i*i)+(j*j)==diagonal)
                {
                    flag = true;
                    break;
                }
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
