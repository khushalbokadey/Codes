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

    int i, n, number, listsize;
    float median;
    char ch[2];
    vector<int>list;
    vector<int>::iterator it, index;

    n = in();
    listsize = 0;

    for(i=0;i<n;i++)
    {
        scanf("%s", ch);
        number = in();

        if(ch[0]=='a')
        {
            list.push_back(number);
            sort(list.begin(),list.end());
            listsize = list.size();
            int mid = (list.size())/2;
            if(listsize%2==0)
            {
                median = (list.at(mid)+(float)list.at(mid-1))/2;
                cout<<median<<endl;
            }
            else
            {
                cout<<list.at(mid)<<endl;
            }
        }
        else if(ch[0]=='r')
        {
            index = lower_bound (list.begin(), list.end(), number);
            if(index!=list.end())
            {
                list.erase(index);
                sort(list.begin(),list.end());
                listsize = list.size();
                if(listsize==0)
                {
                    cout<<"Wrong!\n";
                }
                else
                {
                    int mid = (list.size())/2;
                    if(listsize%2==0)
                    {
                        median = (list.at(mid)+(float)list.at(mid-1))/2;
                        cout<<median<<endl;
                    }
                    else
                    {
                        cout<<list.at(mid)<<endl;
                    }
                }

            }
            else
            {
                cout<<"Wrong!\n";
            }
        }
        /*for (it=list.begin(); it<list.end(); it++)
            cout << ' ' << *it;
        cout<<endl;*/
    }

    return 0;
}
