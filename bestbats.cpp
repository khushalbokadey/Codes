#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int no_of_test , runs[2][11] ;
    int K , i , run,j,x , flag;
    scanf("%d" , &no_of_test);
    while(no_of_test--)
    {
        for(i=0;i<11;i++)
        {
            runs[0][i]=0;
            runs[1][i]=0;
        }
        x=1;
        for(i=0;i<11;i++)
        {
            scanf("%d",&run);
            flag=0;
            for(j=0;j<x;j++)
            {
                if(runs[0][j]==run)
                {
                    runs[1][j]++;
                    flag=1;
                }
            }
            if(flag==0)
            {
                runs[0][x-1]=run;
                runs[1][x-1]=1;
                x++;
            }
        }
        stable_sort(&runs[0][0],&runs[0][x-1]);
        for(i=0;i<x-1;i++)
        printf("\n%d %d" , runs[0][i],runs[1][i]);
    }
    return 0;
}
