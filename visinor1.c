#include<stdio.h>
int main()
{
    int a;
    a = getFinalAmount(20 , "WLLWWWW" , 7);
    printf("%d" , a);
    return 0 ;
}

int getFinalAmount(int initialAmount , char betResults[],int N)
{
/*N is the length of betResults array */
    int betamt ,i , prevamt , finalamt;
    betamt = 0;
    prevamt=1;
    for(i=0;i<N;i++)
    {
        if(betResults[i]=='W')
        {
            betamt+=prevamt;
            prevamt = 1;
        }
        else if(betResults[i]=='L')
        {
            betamt -= prevamt;
            prevamt*=2;
        }
    }
    finalamt = initialAmount + betamt;
    return finalamt;
}
