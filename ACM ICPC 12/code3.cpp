#include <iostream>
#include <cstdio>
#include <algorithm>
#include <deque>

#define lint long long int
#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,a) for(i=0;i<a;i++)
#define INPUT_FROM_FILE freopen("in.txt", "r", stdin);

using namespace std;
int main()
{
    //INPUT_FROM_FILE;
    int n, c, j, tc, l, h, i, arr[1001], arr2[1000000];
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
        sort(arr, arr+n);
        fr(i, n)
        {
            for(j = i; j < n; j++)
            {
                arr2[i*n+j] = arr[i] + arr[j];
            }
        }
        sort(arr2, arr2+n*n);
        fr(i, n);
        {
            int min_index = binary_search(arr, arr+n, l-arr[i]);
            int max_index = binary_search(arr, arr+n, h-arr[i]);
            c += max_index - min_index + 1;
        }
        printf("%d\n", c);
    }
    return 0;
}

