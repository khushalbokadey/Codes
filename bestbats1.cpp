#include<stdio.h>
#include<algorithm>
using namespace std;
struct runs
{
    int i_run , count;
};
int main()
{
    int no_of_test  ;
    struct runs obj[11];
    int K , i , run,j,x , flag;
    scanf("%d" , &no_of_test);
    while(no_of_test--)
    {
        for(i=0;i<11;i++)
        {
            obj[i].i_run=0;
            obj[i].count=0;
        }
        x=1;
        for(i=0;i<11;i++)
        {
            scanf("%d",&run);
            flag=0;
            for(j=0;j<x;j++)
            {
                if(obj[j].i_run==run)
                {
                    obj[j].count++;
                    flag=1;
                }
            }
            if(flag==0)
            {
                obj[x].i_run=run;
                obj[x].count=1;
                x++;
            }
        }
        stable_sort(&obj[0].i_run,&obj[x+1].i_run);
        for(i=0;i<x;i++)
        printf("\n%d %d" , obj[i].i_run,obj[i].count);
    }
    return 0;
}
