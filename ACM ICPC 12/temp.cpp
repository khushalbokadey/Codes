#include <iostream>
#include <cstdio>
#include <algorithm>
#include <deque>

#define lint long long int
#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,a) for(i=0;i<a;i++)
#define INPUT_FROM_FILE freopen("in.txt", "r", stdin);

using namespace std;
int c, n;
void cnt(int arr[], int l, int h)
{
    int i, j, k, indx;
    fr(i, n)
    {
        for(j=i+1;j<n;j++)
        {
            for(k=j+1;k<n;k++)
            {
                indx = arr[i] + arr[j] + arr[k];
                if(indx <= h && indx >= l) c++;
            }
        }
    }
}

int main()
{
    //INPUT_FROM_FILE;
    int tc, l, h, i, arr[1001];
    tc = in();
    while(tc--)
    {
        n = in();
        l = in();
        h = in();
        c = 0;
        fr(i, n)
        {
            arr[i] = in();
        }
        /*if(n == 1 || n == 2)
        {
            printf("0\n");
            continue;
        }*/
        sort(arr, arr+n);
        /*cout << binary_search(arr, 6, 2, 4);
        cout << binary_search(arr, 8);*/
        /*fr(i, n)
        {
            cout << arr[i] << " ";
        }*/
        cnt(arr, l, h);
        printf("%d\n", c);
    }
    return 0;
}
