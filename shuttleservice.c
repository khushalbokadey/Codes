#include<stdio.h>
int main()
{
    int no_of_test , stands , count , i , agencies;
    scanf("%d" , &no_of_test);
    while(no_of_test!=0)
    {
        scanf("%d" , &stands);
        count=0;
        agencies = stands-1;
        for(i=2;i<=agencies;i++)
        {
            if(stands%i==0)
            {
                count++;
            }
        }
        printf("%d\n",agencies-count);
        no_of_test--;
    }
    return 0;
}
