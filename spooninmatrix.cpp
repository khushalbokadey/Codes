#include<stdio.h>
#include<new>
#include<iostream>
using namespace std;
int main()
{
    int no_of_test;
    int R , C , i , j , flag;
    char matrix[101][101];
    scanf("%d" , &no_of_test);
    while(no_of_test!=0)
    {
        scanf("%d %d" , &R , &C);
        //matrix = new char*[R];
        /*for(i=0;i<R;i++)
        {
            matrix[i] = new char[C];
        }*/
        for(i=0;i<R;i++)
        {
            //fflush(stdin);
            scanf("%s" ,matrix[i]);
            /*for(j=0;j<C;j++)
            {
                fflush(stdin);
                fflush(NULL);
                scanf("%c" , &matrix[i][j]);
            }*/
        }
        flag  = 0;
        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
            {
                if(matrix[i][j]=='s'||matrix[i][j]=='S')
                {
                    if(j+4<=C-1)
                    {
                        if((matrix[i][j+1]=='p'||matrix[i][j+1]=='P')&&(matrix[i][j+2]=='o'||matrix[i][j+2]=='O')&&(matrix[i][j+3]=='o'||matrix[i][j+3]=='O')&&(matrix[i][j+4]=='n'||matrix[i][j+4]=='N'))
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if(i+4<=R-1)
                    {
                        if((matrix[i+1][j]=='p'||matrix[i+1][j]=='P')&&(matrix[i+2][j]=='o'||matrix[i+2][j]=='O')&&(matrix[i+3][j]=='o'||matrix[i+3][j]=='O')&&(matrix[i+4][j]=='n'||matrix[i+4][j]=='N'))
                        {
                            flag = 1;
                            break;
                        }
                    }
                }
            }
            if(flag==1)
            {
                printf("There is a spoon!\n");
                break;
            }
        }
        if(flag==0)
        {
            printf("There is indeed no spoon!\n");
        }
        //delete [] matrix;
        no_of_test--;
    }
    return 0;
}
