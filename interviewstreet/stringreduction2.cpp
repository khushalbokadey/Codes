#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<string>
#include<set>
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

int finallength=1;
int value=1;

bool reducestring(string input)
{
    int i, j, len;
    bool flag;
    len = input.length();
    finallength = len;
    if(len==1)
    {
        value = 1;
        return true;
    }

    if(len == 2 && input.at(0) == input.at(1))
    {
        value = 2;
        return true;
    }

    for(i=0;i<len-1;i++)
    {
        if(input.at(i)!=input.at(i+1))
        {
            string left, mid, right, reducedstring;

            left = "";
            right = "";
            if((int)input.at(i)+(int)input.at(i+1) == 195)
            {
                mid = "c";
            }
            else if((int)input.at(i)+(int)input.at(i+1) == 197)
            {
                mid = "a";
            }
            else if((int)input.at(i)+(int)input.at(i+1) == 196)
            {
                mid = "b";
            }

            left = input.substr(0,i);
            right = input.substr(i+2, len-i-2);
            reducedstring = left+mid+right;

            flag = reducestring(reducedstring);
            if(flag)
            {
                finallength=min(finallength, value);
                return flag;
            }
        }
    }
    return false;
}

int main()
{
    INPUT_FROM_FILE();

    int no_of_test, i, j, len;
    string input, temp;
    bool flag;
    char arr[102];

    no_of_test = in();

    while(no_of_test--)
    {
        finallength = 1;
        value = 1;
        input.clear();
        scanf("%s", arr);
        input = arr;
        len = strlen(arr);
        finallength = len;

        reducestring(input);

        cout<<finallength;
        cout<<endl;
    }


    return 0;
}
