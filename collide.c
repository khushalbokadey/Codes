#include<stdio.h>
int main()
{
    int t , N , Ex , Ey , Ax , Ay;
    char ED , AD;
    bool flag;
    scanf("%d",&t);
    while(t!=0)
    {
        scanf("%d%d%c" , &Ex , &Ey , &ED);
        scanf("%d" , &N);
        while(N!=0)
        {
            flag=true;
            scanf("%d%d%c" , &Ax , &Ay , &AD);
            if(ED==AD)
            {
                continue;
            }
            else if(ED=='U' && AD=='D' && Ex!=Ax)
            {
                continue;
            }
            else if(ED=='D' && AD=='L' && Ey<=Ay)
            {
                continue;
            }
            else if(ED=='D' && AD=='R' && Ey<=Ay)
            {
                continue;
            }
            else if(ED=='U' && AD=='L' && Ey>=Ay)
            {
                continue;
            }
            else if(ED=='U' && AD=='R' && Ey>=Ay)
            {
                continue;
            }
            else if(ED=='D' && AD=='U' && Ex!=Ax)
            {
                continue;
            }
            else if(ED=='R' && AD=='L' && Ey!=Ay)
            {
                continue;
            }
            else if(ED=='L' && AD=='R' && Ey!=Ay)
            {
                continue;
            }
            N--;
        }
        t--;
    }
    return 0;
}
