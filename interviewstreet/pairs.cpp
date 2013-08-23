#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<algorithm>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 0; i < n; i++)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

int main()
{
    INPUT_FROM_FILE();
    long long int i, N;
    long long int arr[100003], K, count;

    N = in();
    K = in();

    fill(arr, arr+N, 0);

    fr(i,N)
    {
        arr[i] = in();
    }

    sort(arr, arr+N);

    count = 0;

    fr(i,N)
    {
        if(binary_search(arr, arr+N, arr[i]+K))
        {
            count++;
        }
    }
    cout<<count<<endl;

    return 0;
}
