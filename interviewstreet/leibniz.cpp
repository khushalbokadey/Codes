#include<iostream>
#include<cmath>

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

    int tc, n, i;
    double ans;
    tc = in();
    while(tc--)
    {
        n = in();
        ans = 0;
        fr(i,n)
        {
            ans += ( (pow(-1,i) ) / (2*i + 1));
        }
        printf("%.15g\n",ans);
    }

    return 0;
}
