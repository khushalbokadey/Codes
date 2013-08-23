#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
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

int finallength;

void reducestring(vector<char> input)
{
    vector <char> temp;
    int len, i, j;
    len = input.size();
    if(len<finallength)
    {
        finallength = len;
    }
    temp = input;

    fr(i,len)
    {
        if(i<len-1 && temp.at(i)!=temp.at(i+1))
        {
            if((int)temp.at(i)+(int)temp.at(i+1) == 195)
            {
                temp.erase(temp.begin() + i);
                temp.at(i) = 'c';
            }
            else if((int)temp.at(i)+(int)temp.at(i+1) == 197)
            {
                temp.erase(temp.begin() + i);
                temp.at(i) = 'a';
            }
            else if((int)temp.at(i)+(int)temp.at(i+1) == 196)
            {
                temp.erase(temp.begin() + i);
                temp.at(i) = 'b';
            }
            reducestring(temp);
            temp = input;
        }
    }

}

int main()
{
    INPUT_FROM_FILE();

    int no_of_test, i, j, len;
    vector <char> input, temp;
    bool flag;
    char arr[102];

    no_of_test = in();

    while(no_of_test--)
    {
        input.clear();
        scanf("%s", arr);
        len = strlen(arr);
        finallength = len;
        for(i=0;i<len;i++)
        {
            input.push_back(arr[i]);
        }

        temp = input;
        fr(i,len)
        {
            if(i<len-1 && temp.at(i)!=temp.at(i+1))
            {
                //cout<<temp.at(i)<<" "<<temp.at(i+1)<<endl;
                if((int)temp.at(i)+(int)temp.at(i+1) == 195)
                {
                    temp.erase(temp.begin() + i);
                    temp.at(i) = 'c';
                }
                else if((int)temp.at(i)+(int)temp.at(i+1) == 197)
                {
                    temp.erase(temp.begin() + i);
                    temp.at(i) = 'a';
                }
                else if((int)temp.at(i)+(int)temp.at(i+1) == 196)
                {
                    temp.erase(temp.begin() + i);
                    temp.at(i) = 'b';
                }
                reducestring(temp);
                temp = input;
            }
        }

        cout<<finallength;
        cout<<endl;
    }


    return 0;
}
