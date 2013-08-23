#include<stdio.h>
#include<string.h>
int main()
{
    long N , Q , A , B ,i;
    scanf("%ld %ld", &N , &Q);
    //long* array;
    char* str;
  //  array = (long*)malloc(N*sizeof(long));
    fflush(stdin);
    while(Q>=1)
    {
        gets(str);
        printf("%d" , strlen(str));
    }
    return 0;
}
