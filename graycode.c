#include<stdio.h>
int main()
{
    int num , gnum , dec , t;
    int b[20] , i ,j , bin[20] , n;
    scanf("%d" , &t);
    while(t!=0)
    {
        scanf("%d" , &num);
        if(num == 0)
        {
            printf("\n0");
        }
        else
        {
            i=0;
            //dec to gray
            while(num!=0)
            {
                b[i]=num%2;
                num=num/2;
                i++;
             }
             j=i-1;
             i=i-1;
             //gray to bin

             n=0;
             while(i>=0)
             {
                //printf("%d",b[i]);
                if(i==j)
                {
                    bin[j] = b[i];
                }
                else
                {
                    bin[i] = bin[i+1]^b[i];
                }
                n = n + (pow(2,i)*bin[i]);
                i--;
             }
             printf("\n%d" , n);
        }
        t--;
    }
    return 0;
}
