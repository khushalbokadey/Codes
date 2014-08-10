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

int main()
{
    //INPUT_FROM_FILE();
    long long int a;
    cin >> a;
    if (a==0 || a==1 || a%3==0 || a%6==1)
        cout << "yes\n";
    else
        cout << "no\n";
    return 0;
}
