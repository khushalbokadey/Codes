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

int binary_search(int arr[], int num, int start = 0, int end = n)
{
    //cout << "a";
    if(start >= end) return start-1;
    int mid = (start + end - 1) / 2;
    if(num < arr[mid])
    {
        return binary_search(arr, num, start, mid);
    }
    else if(num > arr[mid])return binary_search(arr, num, mid+1, end);
    if(arr[mid] == num) return mid;
}

void cnt(int arr[], int l, int h)
{
    int i, j, k, indx;
    fr(i, n)
    {
        l -= arr[i];
        h -= arr[i];

        for(j=i+1;j<n;j++)
        {
            l -= arr[j];
            h -= arr[j];

            //cout << l << " " << h;
            indx = binary_search(arr, l, j+1);
            if(indx <= j) indx = j+1;
            //cout << " " << indx;
            while(indx < n && arr[indx] <= h && arr[indx] >= l)
            {
                //cout << "B";
                c ++;
                indx ++;
            }
            //cout << endl;

            l += arr[j];
            h += arr[j];
        }
        //cout << endl;
        l += arr[i];
        h += arr[i];
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
