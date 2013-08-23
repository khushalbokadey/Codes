#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 0; i < n; i++)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input01.txt", "r", stdin);
    #endif
}

int main()
{
    //INPUT_FROM_FILE();
    int i , n, arr[100002], c[100002], count, dec_count;
    bool flag;

    n = in();
    count = 0;
    dec_count=0;

    fr(i,n)
    {
        arr[i] = in();
    }

    c[0]=1;
    count = 1;
    flag = false;
    fr(i,n-1)
    {
        if(arr[i] < arr[i+1])
        {
            if(flag)
            {
                flag = false;
                count = count + (dec_count * (dec_count+1))/2;
                if(dec_count >= c[i-dec_count])
                {
                    count += (dec_count-c[i-dec_count]+1);
                }
                dec_count = 0;
            }
            c[i+1] = c[i] + 1;
            count+=c[i+1];
        }
        else if(arr[i]==arr[i+1])
        {
            if(flag)
            {
                flag = false;
                count = count + (dec_count * (dec_count+1))/2;
                if(dec_count >= c[i-dec_count])
                {
                    count += (dec_count-c[i-dec_count]+1);
                }
                dec_count = 0;
            }
            c[i+1] = 1;
            count+=c[i+1];
        }
        else
        {
            flag = true;
            dec_count++;
            c[i+1] = 1;
        }
    }
    if(flag)
    {
        flag = false;
        count = count + (dec_count * (dec_count+1))/2;
        if(dec_count >= c[i-dec_count])
        {
            count += (dec_count-c[i-dec_count]+1);
        }
        dec_count = 0;
    }

    cout<<count<<"\n";
    return 0;
}
