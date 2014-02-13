#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<map>
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
void insertionSort(int arr[], int size) {

    int i, k, j, curr_ele;
    for (i=1; i<size; i++) {
        curr_ele = arr[i];
        k = i;

        while (k>0 && arr[k-1] > curr_ele) {
            arr[k] = arr[k-1];
            k--;
        }
        arr[k] = curr_ele;
        for (j=0; j<size; j++) {
            cout<< arr[j] << " ";
        }
        cout<<"\n";
    }
}
int main()
{
    INPUT_FROM_FILE();
    int arr[1003], i, size;
    size = in();
    fr(i, size) {
        arr[i] = in();
    }
    insertionSort(arr, size);
    return 0;
}
