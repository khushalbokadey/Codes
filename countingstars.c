#include<stdio.h>
int main()
{
    int arr[100][100];
    int row , col , i ,j , t , px,py,qx,qy , count=0;
    scanf("%d %d" , &row , &col);
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d" , &arr[i][j]);
        }
    }
    scanf("%d",&t);
    while(t!=0)
    {
        scanf("%d%d%d%d" , &px , &py ,&qx , &qy);
        count =0;
        for(i=px-1;i<qx;i++)
        {
            for(j=py-1;j<qy;j++)
            {
                count = count+arr[i][j];
            }
        }
        printf("\n%d" , count);
        t--;
    }
    return 0;
}
