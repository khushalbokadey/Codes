#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 0; i < n; i++)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int tree[101][101], v1, v2, finalcount[101];
int i , n, k, m, j, edgesremoved;
vector <int> stck;

void getcount(int x)
{
    int i, last, currentlast;
    stck.push_back(x);
    for(i=0;i<n;i++)
    {
        if(tree[x][i]==1)
        {
            bool isPresent = (find(stck.begin(), stck.end(), i) != stck.end());
            if(!isPresent)
            {
                getcount(i);
            }
        }
    }
    last = stck.back();
    stck.pop_back();
    if(!stck.empty())
    {
        currentlast = stck.back();
        finalcount[currentlast] += finalcount[last];
    }
}

int main()
{
    INPUT_FROM_FILE();

    n = in();
    m = in();
    fr(i,m)
    {
        v1 = in();
        v2 = in();
        tree[v1-1][v2-1] = tree[v2-1][v1-1] = 1;
    }
    fill(finalcount, finalcount+n, 1);

    getcount(0);

    /*fr(i,n)
    {
        cout<<finalcount[i]<<" ";
    }
    cout<<endl;*/

    fr(i,n)
    {
        if(finalcount[i]%2==0)
        {
            edgesremoved++;
        }
    }

    cout<<edgesremoved-1<<"\n";

    return 0;
}
