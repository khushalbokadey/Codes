#include<stdio.h>
int main()
{
    char str[101];
    int no_of_test , count , i;
    scanf("%d" , &no_of_test);
    while(no_of_test!=0)
    {
        count=0;
        scanf("%s" , str);
        for(i=0;str[i]!='\0';i++)
        {
            if(str[i]=='A' || str[i]=='D' || str[i]=='O' || str[i]=='P' || str[i]=='Q' || str[i]=='R')
                count++;
            if(str[i]=='B')
                count+=2;
        }
        printf("%d\n" , count);
        no_of_test--;
    }
    return 0;
}
