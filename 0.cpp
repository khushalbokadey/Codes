#include<stdio.h>

int main()
{
    short a,b;
    scanf("%hu",&a);
    while(a--)
    {
        printf("%hu\n",a);
        scanf("%hu",&b);
        printf("%hu\n",a);
    }
    return 0;
}
