#include<stdio.h>
#include<string.h>
int count(char[],int);
int fact(int);
int main()
{
    int X , N , i , total=0 , j;
    char **arr;
    scanf("%d %d" , &X , &N);
    arr = (char**)malloc(N);
    fflush(stdin);
    for(i=0;i<N;i++)
    {
        arr[i] = (char*)malloc(55);
        for(j=0;j<=54 ; j++)
        {
            scanf("%c",&arr[i][j]);
        }
        for(j=0;j<=54 ; j++)
        {
            printf("%c",arr[i][j]);
        }
        printf("\n%d " , strlen(arr[i]));
    }
    for(i=0;i<N;i++)
    {
        total+=count(arr[i],X);
    }
    printf("%d" , total);
    return 0;
}
int count(char* arr , int X)
{
    int i , j , count =0 , ret;
    printf("%d" , strlen(arr));
    for(i=1 ; i<=9 ; i++)
    {
        for(j= (6*(i-1)) - (2*(i-1)) + 1 ; j<= (6*i)-(2*i) ; j++)
        {
            printf("\n%d" , j);
            if(arr[j-1] == '0')
                count++;
        }
        if(arr[54 - (i*2)] == '0')
            count++;
        if(arr[54 - (i*2) + 1] == '0')
            count++;
    }
    printf("count = %d" , count );
    if(count>=X)
    {
        return (fact(count)) / ((fact(X)) * (fact(count-X)) );
    }
    return 0;
}
int fact(int n)
{
    int i , ret=1;
    for(i=1;i<=n ; i++)
        ret*=i;
    return ret;
}

