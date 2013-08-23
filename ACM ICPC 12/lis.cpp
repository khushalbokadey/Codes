#include <iostream>
#include <stdio.h>
#include <deque>
#include <cstring>

using namespace std;
int count = 0;
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
// Binary search (note boundaries in the caller)
int CeilIndex(int A[], int l, int r, int key) {
    int m;

    while( r - l > 1 ) {
        m = l + (r - l)/2;
        (A[m] >= key ? r : l) = m; // ternary expression returns an l-value
    }

    return r;
}

int LongestIncreasingSubsequenceLength(int A[],int j, int size, int a, int b) {
    // Add boundary case, when array size is one

    int *tailTable   = new int[size];
    int len; // always points empty slot

    memset(tailTable, 0, sizeof(tailTable[0])*size);

    tailTable[0] = A[j];
    len = 1;
    for( int i = j + 1; i <= b; i++ ) {
        if( A[i] < tailTable[0] )
            // new smallest value
            tailTable[0] = A[i];
        else if( A[i] >= tailTable[len-1] )
            // A[i] wants to extend largest subsequence
            tailTable[len++] = A[i];
        else
            // A[i] wants to be current end candidate of an existing subsequence
            // It will replace ceil value in tailTable
            tailTable[CeilIndex(tailTable, -1, len-1, A[i])] = A[i];
    }
    //for(int i = 0; i < size; i++)
    //cout<<tailTable[i];
    delete[] tailTable;

    return len;
}

int countZeros (int A[], int n, int a, int b){
    int count = 0;
    for(int i = a; i < b; i++){
        if(A[i] == 0){
            count++;
        }
    }
    return count;
}
int countZeroFromStart(int A[], int n, int a, int b){


    int i = a;
    while(A[i] != 1 && i < b){
        count++;
        i++;
    }
    //cout << count << " ";
    return i;
}

int main() {
    freopen("in.txt", "r", stdin);
    char ch[100002];
    int tc, n, q, a, b, i, A[100002], result, result1;;
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d\n", &n);
        cin.getline(ch, 100000);
        for(i=0;i<n;i++)
        {
            A[i] = ch[i] - 48;
        }
        scanf("%d", &q);
        while(q--)
        {
            result = count = 0;
            scanf("%d %d", &a, &b); a--; b--;
            i = countZeroFromStart(A, n, a, b);
            //cout<<i<<" ";
            result1 = LongestIncreasingSubsequenceLength(A, i, n, a, b);
            //cout<<result1<<" ";
            count = count + result1;
                int result2 = countZeros(A, n, a, b);
                //cout << result2 << " ";
            result = count > result2 ? count :result2;
            cout<<result<<endl;
        }
    }
    //int A[] = {0,0,1,1,1,0,1,0,0,1,1,1,0};
    //int n = ARRAY_SIZE(A);
    return 0;
}
