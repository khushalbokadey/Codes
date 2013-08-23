#include<stdio.h>
int main()
{
    int *element , *count;
    int num , x , i ,j , size ,value ,maxcount , maxcountval;
    int flag;
    scanf("%d" , &num);
    while(num!=0)
    {
        scanf("%d" , &x);
        element = (int*) malloc(x*sizeof(int));
        count = (int*) calloc(x,sizeof(int));
        size = x;
        j=0;
        while(x!=0)
        {
            scanf("%d" , &value);
            if(size==x)
            {
                element[j] = value;
                count[j]++;
                j++;
            }
            else
            {
                flag = 0;
                for(i=0 ; i<=size-x-1 ;i++)
                {
                    if(element[i]==value)
                    {
                        count[i]++;
                        flag = 1;
                        size--;
                        break;
                    }
                }
                if(flag ==0)
                {
                    element[j] = value;
                    count[j]++;
                    j++;
                }
            }
            x--;
        }
        maxcount = count[0];
        maxcountval = element[0];
        for(i=1;i<size;i++)
        {
            if(maxcount==count[i])
            {
                if(maxcountval>element[i])
                    maxcountval = element[i];
            }
            if(maxcount<count[i])
            {
                maxcount = count[i];
                maxcountval = element[i];
            }
        }
        printf("\n%d %d" , maxcountval , maxcount);
        num--;
    }
    return 0;
}
