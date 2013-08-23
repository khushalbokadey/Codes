#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int i , j ,len , spcount , k , l;
    fflush(stdin);
    gets(str);
    len = strlen(str);
    for(i=len-1;i>=0;i--)
    {
        spcount=0;
        j=i;
        printf("%d" , j);
        fflush(stdin);
        while(str[j]==' ' || j==0)
        {
            j--;
            printf("%c",' ');
        }
        k=j;
        while(str[j]!=' ' || j==0)
        {
            j--;
        }
        fflush(stdin);
        for(l=j;l<=k;l++)
            printf("%c" , str[l]);
        printf("%d" , j);
        i=j+1;
    }
    return 0;
}
