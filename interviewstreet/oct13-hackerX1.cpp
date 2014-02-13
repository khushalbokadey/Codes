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
    multimap<int,int> frequency_map;
    multimap<int,int>::iterator it1;
    multimap<int,int>::iterator it2, temp;
    int N, ti[100003], fi[100003], i, j, count, diff;
    N = in();
    for (i=0; i<N; i++) {
        ti[i] = in();
        fi[i] = in();
        frequency_map.insert(pair<int,int>(fi[i], ti[i]));
    }

    //for (it1=frequency_map.begin(); it1!=frequency_map.end(); ++it1) {
      //  cout << (*it1).first << "+>" << (*it1).second <<"\n";
    //}
    count = frequency_map.size();
    it1=frequency_map.begin();
    it1++;
    for (; it1!=frequency_map.end(); ++it1) {
        it2 = it1;
        advance(it2, -1);
        while (it2!=frequency_map.begin()) {
            diff = abs((*it1).first - (*it2).first);
            temp = it2;
            advance(temp, 1);
            if ( (abs((*it2).second - (*it1).second) >= diff) && ( (*temp).first != (*it1).first) && (abs( ((*it1).second - (*temp).second) ) >= diff)) {
                frequency_map.erase(it2);
                count--;
            }
            it2--;
        }
    }

    cout << count << "\n";
    return 0;
}
