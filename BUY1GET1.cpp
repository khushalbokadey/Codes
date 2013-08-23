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


int main()
{
    INPUT_FROM_FILE();

    map<char,int> charcount;
    map<char,int>::iterator it;

    int no_of_test, i, j, len, price;
    char arr[202];

    no_of_test = in();

    while(no_of_test--)
    {
        scanf("%s",arr);
        len = strlen(arr);
        charcount.clear();
        price = 0;
        for(i=0;i<26;i++)
        {
            char ch;
            ch = 65+i;
            charcount.insert(std::pair<char,int>(ch,0));
            ch = 97+i;
            charcount.insert(std::pair<char,int>(ch,0));
        }
        fr(i,len)
        {
            it = charcount.find(arr[i]);
            it->second++;
        }
        for(it= charcount.begin();it!=charcount.end(); it++)
        {
            if(it->second > 0)
            {
                price = price + (it->second / 2) + (it->second %2);
            }
        }
        cout<<price<<endl;
    }

    return 0;
}
