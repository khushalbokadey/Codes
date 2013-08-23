#include<stdio.h>
int main()
{
    int no , ar1[100] ,ar2[100] , i , j, count , maxcount , k;
    scanf("%d" , &no);
    for(i=0;i<no;i++)
    {
        scanf("%d" , &ar1[i]);
    }
    for(i=0;i<no;i++)
    {
        scanf("%d" , &ar2[i]);
    }
    maxcount=1;
    for(i=0;i<no;i++)
    {
        count=1;
        for(j=0;j<no;j++)
        {
            if(i!=j)
            {
                if(ar1[j]>ar1[i] && ar1[j]<ar2[i])
                {
                    count++;
                    for(k=0;k<no;k++)
                    {
                        if(k!=i && k!=j)
                        {
                            if((ar1[k]>ar1[i] && ar1[k]<ar2[i]) && (ar1[k]>ar1[j] && ar2[k]>ar2[j]))
                                count--;
                        }
                    }
                }
            }
        }
        if(count>maxcount)
            maxcount=count;
    }
    printf("%d" , maxcount);
    return 0;
}
