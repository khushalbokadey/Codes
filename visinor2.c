#include<stdio.h>
int main()
{
    int n;
    n = getIntegerComplement(11);
    printf("%d\n" , n);
    return 0 ;
}
int getIntegerComplement(int n)
{
    int binary_n[50] , comp_num , pow;
    int i , j , k;
    i=n;
    j=0;
    while(i!=0)
    {
        binary_n[j] = i%2;
        i/=2;
        j++;
    }
    j--;
    for(k=0 ; k<=j;k++)
    {
        if(binary_n[k]==1)
            binary_n[k]=0;
        else
            binary_n[k]=1;
    }
    comp_num = 0;
    pow=1;
    for(k=0 ; k<=j;k++)
    {
        if(k!=0)
        {
            pow*=2;
        }
        comp_num += pow*binary_n[k];
    }
    return comp_num;
}
