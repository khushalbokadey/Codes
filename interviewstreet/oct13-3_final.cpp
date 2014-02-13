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
    int N, K, arr[100003], i, j, min, k, first, last;
    int diff_arr[100003], vector_size, count_size, min_index;
    vector <int> index_arr;
    vector <long int> count_arr;
    long int count;
    N = in();
    K = in();
    fr(i,N) {
        arr[i] = in();
    }
    sort(arr, arr+N);
    min = arr[K-1] - arr[0];
    for (i=1,j=i+K-1; j<N; i++,j++) {
        if ((arr[j]-arr[i]) < min) {
            min = arr[j] - arr[i];
        }
    }
    for (i=0,j=i+K-1; j<N; i++,j++) {
        if ((arr[j]-arr[i]) == min) {
            index_arr.push_back(i);
        }
    }
    vector_size = index_arr.size();
    for (k=0; k<vector_size; k++) {
        first = index_arr.at(k);
        last = first + K - 1;
        count = 0;
        for (i=first; i<last; i++) {
            for (j=i+1; j<=last; j++) {
                count += (arr[j] - arr[i]);
            }
        }
        count_arr.push_back(count);
    }
    count_size = count_arr.size();
    min_index = 0;
    for (i=1; i<count_size; i++) {
        if (count_arr.at(i) < count_arr.at(min_index))
            min_index = i;
    }
    cout << count_arr.at(min_index) << "\n";
    return 0;
}
