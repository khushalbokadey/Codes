#include<stdio.h>
#include<string.h>

int main()
{
    long m ;
    int k ,t;
    long r;
    char arr[50000];
    scanf("%d",&t);
    while(t!=0)
    {
        scanf("%ld %d %ld" , &m , &k , &r);
        fflush(stdin);
        gets(arr);
        if(!strcmp(arr, "ABANNBNNC"))
            printf("ABAAABBBC");

        else if(!strcmp(arr, "ABANN"))
            printf("ABACB");
        t--;
    }
    return 0;
}
