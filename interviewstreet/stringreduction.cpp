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

bool myfunction (int i,int j) { return (i>j); }

int main()
{
    INPUT_FROM_FILE();

    int no_of_test, i, j, len;
    vector <char> input;
    bool flag;
    char arr[102];

    no_of_test = in();

    while(no_of_test--)
    {
        input.clear();
        scanf("%s", arr);
        len = strlen(arr);
        for(i=0;i<len;i++)
        {
            input.push_back(arr[i]);
        }
        for(i=0;i<len-1;i++)
        {
            if(input.at(i)!=input.at(i+1))
            {
                j = i+1;
                flag = input.at(j)!=input.at(j-1);
                while(flag)
                {
                    if((int)input.at(j)+(int)input.at(j-1) == 195)
                    {
                        input.erase(input.begin() + j-1);
                        input.at(j-1) = 'c';
                        len--;
                    }
                    else if((int)input.at(j)+(int)input.at(j-1) == 197)
                    {
                        input.erase(input.begin() + j-1);
                        input.at(j-1) = 'a';
                        len--;
                    }
                    else if((int)input.at(j)+(int)input.at(j-1) == 196)
                    {
                        input.erase(input.begin() + j-1);
                        input.at(j-1) = 'b';
                        len--;
                    }
                    j--;
                    if(j>0)
                    {
                        flag = input.at(j)!=input.at(j-1);
                    }
                    else
                    {
                        flag = false;
                    }
                }
            }
        }

        cout<<input.size();
        cout<<endl;
    }


    return 0;
}
