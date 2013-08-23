#include<stdio.h>
int main()
{
    int no_of_test , N , M , A , B , X , Y , Q;
    int roads[101][101] , i ,j , k;
    scanf("%d" , &no_of_test);
    while(no_of_test!=0)
    {
        scanf("%d %d" , &N , &M);
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                if(i==j)
                    roads[i][j]=1;
                else
                    roads[i][j]=0;
            }

        }
        while(M!=0)
        {
            scanf("%d %d" , &A , &B);
            roads[A][B]=1;
            roads[B][A]=1;
            M--;
        }
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                for(k=j+1;k<N;k++)
                {
                    if(roads[i][j]==1 && roads[i][k]==1)
                    {
                        roads[j][k]=1;
                        roads[k][j]=1;
                    }

                }
            }
        }
        scanf("%d" , &Q);
        while(Q!=0)
        {
            scanf("%d %d" , &X , &Y);
            if(roads[X][Y]==1)
                printf("YO\n");
            else
                printf("NO\n");
            Q--;
        }
        no_of_test--;
    }
    return 0;
}
