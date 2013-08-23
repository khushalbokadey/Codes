#include<stdio.h>
int factors[1000], top;
int count(int n);
int main()
{
    int tc, num;
    scanf("%d", &tc);
    while(tc--)
    {
        top = 0;
        scanf("%d", &num);
        printf("%d\n", count(num));
    }
    return 0;
}
int count(int n)
{
    int i, j, count = n-1;
    bool flag;
    for(i=2;i<=n/2;i++)
    {
        if(n%i == 0)
        {
            flag = true;
            for(j=0;j<top && flag;j++)
                if(i%factors[j] == 0)
                    flag = false;
            if(flag)
            {
                factors[top++] = i;
                count -= (n-1)/i;
            }
        }
    }
    for(i=1;i<top;i++)
    {
        for(j=0;j<top-i;j++)
        {
            factors[top*i+j] = factors[top*(i-1)+j] * factors[top*(i-1)+j+1];
            if(factors[top*i+j] <= 10000)
                count += (n-1)/factors[top*i+j];
        }
    }
    return count;
}
