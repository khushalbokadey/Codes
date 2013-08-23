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
    freopen("input01.txt", "r", stdin);
    #endif
}

bool myfunction (int i,int j) { return (i>j); }

int main()
{
    INPUT_FROM_FILE();

    int i, n, number, listsize, count, index, medint;
    float median;
    char ch[2];
    bool flag;
    multiset<int> listset;
    multiset<int>::iterator it, previous, temp;

    n = in();

    for(i=0;i<n;i++)
    {
        flag = false;
        scanf("%s", ch);
        number = in();
        median = 0;

        if(ch[0]=='a')
        {
            listset.insert(number);
            if(listset.size()==1)
                previous = listset.begin();
            else if(number >= *previous && listset.size()%2 == 0)
                previous++;
            else if(number < *previous && listset.size()%2 != 0)
                previous--;
        }
        else if(ch[0]=='r' && listset.size()>0)
        {
            it = listset.find(number);

            if(it == listset.end() || *it != number)
            {
                cout << "Wrong!\n"; continue;
            }
            else if(*previous == number)
            {
               if(listset.size()%2 != 0)
                    previous++;
               else
               {
                  temp = previous;
                  temp--;
                  if(*temp != number)
                    previous--;
               }
            }
            else if(number>=*previous && listset.size()%2 == 0)
                previous--;
            else if(number<=*previous && listset.size()%2 != 0)
                previous++;
            listset.erase(it);
        }

        listsize = listset.size();

        if(listset.size()==0)
            cout << "Wrong!\n";
        else if(listset.size()%2!=0)
            cout << *previous << endl;
        else
        {
              median = *previous;
              previous--;
              median = (median+*previous);
              medint = median;
              if(medint%2==0)
                  printf("%.0lf\n", median/2.);
              else
                  printf("%.1lf\n", median/2.);
              previous++;
        }

    }

    return 0;
}
