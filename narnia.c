#include<stdio.h>

int refer[2][501] , t , n;
int sp[501][501] , is[501][501];
int main()
{
    int i , j;
    scanf("%d",&t);
    while(t!=0)
    {
        scanf("%d",&n);
        setrefer();
        for(i=0 ; i<n;i++)
        {
            for(j=0;j<=n;j++)
            {
                scanf("%d",&sp[i][j]);
            }
        }
        for(i=0 ; i<n;i++)
        {
            for(j=0;j<=n;j++)
            {
                scanf("%d",&is[i][j]);
            }
        }
        if(!sppref())
        {
           ispref();
        }
    }
    return 0;
}
void setrefer()
{
    int j ;

        for(j=0;j<501;j++)
        {
            refer[0][j] = j+1;
            refer[1][j] = 0;
        }

    }
}
bool sppref()
{
    int i ,j;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(refer[1][j]==0)
            {
                if(chkrepeat(i,sp[j][i] , 1)==false)
                {
                    refer[1][j-1] = sp[i][j];
                }
            }
        }
    }

    for(i=0;i<=n;i++)
    {
        if(refer[1][i]==0)
            return false;

    }
    return true;
}
bool chkrepeat(int j , int num , int chk)
{
    int i;
    if(chk==1)
    {
        for(i=0;i<n;i++)
        {
            if(sp[i][j])
        }
    }
}
