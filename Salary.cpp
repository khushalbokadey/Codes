#include<iostream>
#include<string.h>
#include<stdio.h>
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
    int no_of_test, i , n, salary[102], totalcount;

    no_of_test = in();

    while(no_of_test--)
    {
        totalcount = 0;
        n = in();
        for(i=0;i<n;i++)
        {
            salary[i] = in();
        }
        sort(salary, salary+n);
        for(i=1;i<n;i++)
        {
            totalcount += (salary[i]-salary[0]);
        }
        cout<<totalcount<<endl;
    }

    return 0;
}
