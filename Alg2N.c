#include<stdio.h>
int answer[200];
int main()
{
    int no_of_test , pow , temp , i , j , count , value , sum;
    scanf("%d" , &no_of_test);
    while(no_of_test!=0)
    {
        sum = 0;
        scanf("%d" , &pow);
        answer[0] = 1;
        temp = 0;
        i=1;
        count = 1;
        while(pow!=0)
        {
            count =0;
            for(j=0;j<i ; j++)
            {
                value = answer[j]*2 + temp;
                answer[j] = value%10;
                temp = value/10;
                count++;
            }
            while(temp!=0)
            {
                answer[count] = temp%10;
                temp/=10;
                count++;
            }
            i=count;
            pow--;
        }
        for(j=count-1;j>=0 ; j--)
        {
            sum +=answer[j];
        }
        printf("%d\n" , sum);
        no_of_test--;
    }
    return 0;
}
