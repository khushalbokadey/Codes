#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<algorithm>
#include <vector>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 0; i < n; i++)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    //freopen("ip1.txt", "r", stdin);
    freopen("input1.txt", "r", stdin);
    freopen("op1.txt", "w", stdout);
    #endif
}
int arr1[20],n,k,m;

int recurse(int i , int arr[])
{
    int a[20];
    int max1=0;int maxf=0;bool good=true;

    if(i<n)
    {
        for(int j=0;j<n;j++)
        {
            a[j]=arr[j];
        }
        int aa=recurse(i+1,a);
        a[i]++; // with incremented case
        int bb=recurse(i+1,a);
        int c=min(aa,bb);  // choosing minimum value
        return c;
    }
    else
    {
        for(int y=0;y<n;++y)
            cout<<arr[y]<<" ";
        cout<<endl;
        for(int x=0;x<=n-k;x++)
        {
            max1=0;maxf=0;
            for(int y=x;y<k+x;y++)
            {
               max1=max(max1,arr[y]);
            }
            for(int y=x;y<k+x;y++)
            {
               if(arr[y]==max1) maxf++;
            }
            if(maxf>=m)
                good=false;

        }
        cout<<"good: "<<good<<endl;
        int change=0;
        for(int x=0;x<n;x++)
        {
            if(arr[x]!=arr1[x]) change++;
        }
        if(good==true)
            return change;
        else return -1;
    }
}

int main()
{
    INPUT_FROM_FILE();
    int no_of_test, i , j;
    int arr[20], windowlen[20], noofoperations;
    vector<int> arrestindex, currentmaxindex;

    no_of_test = in();

    while(no_of_test--)
    {
        n = in();
        k = in();
        m = in();

        fr(i,n)
        {
            arr1[i] = in();
        }

        if(m==1)
        {
            cout<<"-1\n";
        }
        else
        {
            int max1=0;int maxf=0;bool good=true;
            for(int x=0;x<=n-k;x++)
            {
                max1=0;maxf=0;
                for(int y=x;y<k+x;y++)
                {
                   max1=max(max1,arr1[y]);
                }
                for(int y=x;y<k+x;y++)
                {
                   if(arr1[y]==max1) maxf++;
                }

            }
            cout<<endl;
            if(maxf<m)
            {
               cout<<"0\n";
            }
            else
            {
                cout<<recurse(0,arr1)<<endl;
            }
        }

    }

    return 0;
}
