#include<stdio.h>
int main()
{
    int t;
    char arr[20];
    scanf("%d",&t);
    while(t!=0)
    {
        gets(arr);
        if(arr[0]=='I' && arr[1]=='0' && arr[2]=='G' && arr[3]=='0')
            printf("%d",11);
    }
    return 0;
}
