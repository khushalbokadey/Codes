#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
#include<set>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 0; i < n; i++)
#define diff(a,b) (b-a)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}

int main()
{
    INPUT_FROM_FILE();
    map<int,set<int> > frequency_map;
    map<int,set<int> >::iterator map_it1, map_it2;
    set<int> ::iterator set_it1, set_it2, temp;
    int count, diff;
    int N, ti[100003], fi[100003], i, j;
    N = in();
    for (i=0; i<N; i++) {
        ti[i] = in();
        fi[i] = in();
        frequency_map[fi[i]].insert(ti[i]);
        //frequency_map.insert (pair<int,int>(fi[i],ti[i]));
    }
    count = frequency_map.size();

//    for (map_it1=frequency_map.begin(); map_it1!=frequency_map.end(); ++map_it1) {
//        cout<<(*map_it1).first << "\n";
//        for (set_it1 = (*map_it1).second.begin(); set_it1!=(*map_it1).second.end(); set_it1++) {
//            cout<< *set_it1 << " ";
//        }
//        cout<<"\n";
//    }
    map_it1=frequency_map.begin();
    map_it1++;
    for (; map_it1!=frequency_map.end(); ++map_it1) {
        for (map_it2 = frequency_map.begin(); map_it2!=map_it1; map_it2++) {
            diff = (*map_it1).first - (*map_it2).first;
            for (set_it1 = (*map_it1).second.begin(); set_it1!=(*map_it1).second.end(); set_it1++) {
                for (set_it2 = (*map_it2).second.begin(); set_it2!=(*map_it2).second.end(); set_it2++) {
                    temp = set_it2;
                    advance(temp, 1);
                    if ( abs((*set_it1 - *set_it2)) >= diff && abs((*set_it1 - *temp)) >= diff ) {
                        (*map_it1).second.erase(set_it1);
                        count--;

                    }
                }
            }
        }
    }
    cout << count << "\n";
    return 0;
}
