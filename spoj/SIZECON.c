#include<stdio.h>
int main()
{
    int no_of_test, num,count=0;
    scanf("%d",&no_of_test);
    while(no_of_test)
    {
        scanf("%d",&num);
        if(num>0){count+=num;}
        no_of_test--;
    }
    printf("%d\n",count);
    return 0;
}
