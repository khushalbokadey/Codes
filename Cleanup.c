#include<stdio.h>
int main()
{
    int arr[1002] , i , j , no_of_test , m , n , chef[1000] , asst[1000];
    int k , l;
    bool flagc , flaga;
    scanf("%d" , &no_of_test);
    while(no_of_test!=0)
    {
        scanf("%d %d" , &m , &n);
        for(i=1;i<=n;i++)
        {
            arr[i] = 0;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d" , &j);
            arr[j] = 1;
        }
        flagc = false;
        flaga = true;
        k=0; l = 0;
        for(i=1;i<=n;i++)
        {
            if(arr[i]==0 && flagc==false && flaga== true)
            {
                chef[k] = i;
                flagc = true;
                flaga=false;
                k++;
            }
            if(arr[i]==0 && flaga==false && flagc== true)
            {
                asst[l] = i;
                flaga = true;
                flagc=false;
                l++;
            }
        }
        for(i=0;i<k,i++)
            printf("\n%d " , chef[i]);
        for(i=0;i<l,i++)
            printf("\n%d " , asst[i]);
        no_of_test--;
    }
    return 0;
}
