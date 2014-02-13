#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 0; i < n; i++)
#define diff(a,b) (b-a)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}


int main()
{
    INPUT_FROM_FILE();
    int N, K, arr[100003], i, j, first, last, min;
    int diff_arr[100003], count=0;
    N = in();
    K = in();
    fr(i,N) {
        arr[i] = in();
    }
    sort(arr, arr+N);
    min = arr[K-1] - arr[0];
    first = 0;
    last = K-1;
    for (i=1,j=i+K-1; j<N; i++,j++) {
        if ((arr[j]-arr[i]) < min) {
            min = arr[j] - arr[i];
            first = i;
            last = j;
        }
    }
    diff_arr[0] = arr[first+1] - arr[first];
    for (i=first+1; i<last; i++) {
        diff_arr[i-first] = diff_arr[i-first-1] + arr[i+1] - arr[i];
    }
    for (i=0; i<K-1; i++) {
        cout<< diff_arr[i] << " ";
    }
    cout<<endl;
    for (i=0; i<K-1; i++) {
        count += diff_arr[i];
    }
    for (i=0; i<K-1; i++) {
        for (j=i+1; j<K-1; j++) {
            count += diff(diff_arr[i], diff_arr[j]);
        }
    }
    cout<< count<<"\n";
    return 0;
}
