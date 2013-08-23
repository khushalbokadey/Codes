#include<stdio.h>
#include<math.h>
int main()
{
    int no_of_lines , num , Z , i;
    scanf("%d",&no_of_lines);
    for(i =0 ; i< no_of_lines ; i++)
    {
        scanf("%d",&num);
        Z=0;
        while(num)
        {
            Z += num/5;
            num/=5;
        }
        printf("\n%d" , Z);
    }
    return 0;
}
