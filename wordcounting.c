#include<iostream>
#include<stdio>
#include<string>

using namespace std;
long long fact(int);
char ans[200];
int main()
{
    char str[501];
    char *element;
    int no_of_test , len , *count , size , x , i , j;
    long long total;
    int flag;
    scanf("%d",&no_of_test);
    while(no_of_test!=0)
    {
        fflush(stdin);
        fgets(str, 500, stdin);
        len = strlen(str);
        len--;
        printf("%d", len);
        element = (char*) malloc(len);
        count = (int*) calloc(len,sizeof(int));
        x = len;
        size = len;
        j=0;
        while(x!=0)
        {
            if(size==x)
            {
                element[j] = str[len-x];
                count[j]++;
                j++;
            }
            else
            {
                flag = 0;
                for(i=0 ; i<=size-x-1 ;i++)
                {
                    if(element[i]==str[len-x])
                    {
                        count[i]++;
                        flag = 1;
                        size--;
                        break;
                    }
                }
                if(flag ==0)
                {
                    element[j] = str[len-x];
                    count[j]++;
                    j++;
                }
            }
            x--;
        }
        total = fact(len);
        for(i=0;i<=size;i++)
        {
            if(count[i]!=1)
            {
                total/=fact(count[i]);
            }
        }
        cout<<total;
        no_of_test--;
    }
    return 0;
}
long long fact(int num)
{
    long long i, f=1;
    /*for(i=2 ; i<=num ;i++)
    {
        f*=i;
    }*/
    return f;
}
char[] mul(int num)
{
    int len,i;
    len = strlen(ans);
    char
    for(i=len-1 ; i>=0;i--)
    {

    }
}
