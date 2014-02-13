#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<cmath>
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

int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   return K[n][W];
}

int main()
{
    INPUT_FROM_FILE();
    int T, N, W, i, answer;
    int wt[1003], val[1003];
    cin >> T;
    while (T--) {
        cin >> N >> W;
        for (i=0; i<N; i++) {
            cin>> wt[i];
        }
        for (i=0; i<N; i++) {
            cin>> val[i];
        }
        answer = knapSack(W, wt, val, N);
        cout << answer << "\n";
    }
    return 0;
}
