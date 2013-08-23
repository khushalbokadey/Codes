#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

char arr[1000005];
void inc();
bool ispalin(char[]);
int main()
{
    int no_of_test;
    long i , j , len;
    bool flag;
    scanf("%d" , &no_of_test);
    while(no_of_test!=0)
    {
        scanf("%s",&arr);
        inc();
        while(!ispalin(arr))
        {
            inc();
        }
        if(flag==true)
        {
            cout<<arr<<"\n";
        }
        no_of_test--;
    }
    return 0;
}

bool ispalin(char arr[])
{
    long len , i , j;
    bool flag;
    len = strlen(arr);
    flag = true;
    for(i=0;i<len/2;i++)
    {
        if(arr[i]!=arr[len-1-i])
        {
            flag = false;
            break;
        }
    }
    return flag;
}
void inc()
{
    long len , j , i;
    bool flag;
    len = strlen(arr);
    flag = true;
    for(i=0;i<len;i++)
    {
        if(arr[i]!='9')
        {
            flag=0;
        }
    }

    if(flag==1)		/* if all the digits are 9 then just make 1st element 1 and others 0 increasing len by1 */
    {
        arr[0] = '1';
        for(i=1;i<=len;i++)
        {
            arr[i] = '0';
        }
        len++;
    }
    else			/*else go for other numbers*/
    {
        if(arr[len-1]=='9')			/* if last digit is 9 , subtract by 9 as they are ascii codes*/
            arr[len-1]= '0';
        else				/* else increase  char by 1*/
            arr[len-1]++;
        j = len-1;
        if(arr[len-1]=='0')			/* make the changes in the digits accordingly if last is made 0*/
        {
            j--;
            while(arr[j+1]=='0' && j!=0)
            {
                if(arr[j]=='9')
                    arr[j]= arr[j] -9;
                else
                    arr[j]= arr[j]  + 1;
                j--;
            }
        }
    }
}
