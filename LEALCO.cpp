#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<algorithm>
#include <vector>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 0; i < n; i++)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    //freopen("ip1.txt", "r", stdin);
    freopen("input1.txt", "r", stdin);
    #endif
}

int main()
{
    INPUT_FROM_FILE();
    int no_of_test, i , n, k, m, j;
    int arr[20], windowlen[20], noofoperations;
    vector<int> arrestindex, currentmaxindex;

    no_of_test = in();

    while(no_of_test--)
    {
        n = in();
        k = in();
        m = in();

        fr(i,n)
        {
            arr[i] = in();
        }

        if (m < 2 || m > n || m > k)
        {
            cout<<"-1\n";
        }
        else
        {
            arrestindex.clear();
            currentmaxindex.clear();
            noofoperations = 0;
            for (i=0 ; i < n ; i++)
            {
                    if (i + k <= n)
                    {
                            int maxElements = 0;
                            for (j = 0 ; j < k ; j++)
                            {
                                    windowlen[j] = arr[i + j];
                            }

                            int max = -1;
                            int currentindex = -1;
                            for (int j = 0 ; j < k ; j++)
                            {
                                    if (windowlen[j] > max)
                                    {
                                            max = windowlen[j];
                                            maxElements = 1;
                                            currentindex = j;
                                    }
                                    else if (windowlen[j] == max)
                                    {
                                            max = windowlen[j];
                                            maxElements += 1;
                                            currentindex = j;
                                    }
                            }

                            if (currentindex > -1 && max > -1 && maxElements >= m)
                            {
                                    arrestindex.push_back(i);
                                    currentmaxindex.push_back(currentindex);
                            }
                    }
            }
            /*cout<<endl;
            for (i = 0 ; i < arrestindex.size() ; i++)
            {
                cout<<arrestindex.at(i)<<" ";
            }
            cout<<endl;
            for (i = 0 ; i < currentmaxindex.size() ; i++)
            {
                cout<<currentmaxindex.at(i)<<" ";
            }
            cout<<endl;*/

            for (i = 0 ; i < arrestindex.size() ; i++)
            {
                    int index = arrestindex.at(i);
                    int temp = 0;
                    for (j = i + 1 ; j < arrestindex.size() ; j++)
                    {
                            if (arrestindex.at(j) - index <= k && currentmaxindex.at(i) >= arrestindex.at(j))
                                    temp++;
                            else
                                    break;
                    }
                    if (temp > 0)
                    {
                            i += temp + 1;
                            temp = 0;
                            noofoperations += 1;
                    }
                    else
                    {
                            noofoperations += 1;
                            i +=1;
                    }
            }

            if (arrestindex.size() == 1)
            {
                    noofoperations = 1;
            }

            cout<<noofoperations<<"\n";
        }

    }

    return 0;
}
