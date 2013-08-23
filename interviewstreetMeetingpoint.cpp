#include<iostream>
#include<set>

using namespace std;

int main()
{
    int no_of_people;
    long long x,y;
    cin>>no_of_people;

    set< pair<long long, long long> > myset;
    set< pair<long long, long long> >::iterator iter;

    while(no_of_people)
    {
        cin>>x>>y;
        pair<long long,long long> p1 = make_pair(x,y);
        myset.insert(p1);
        no_of_people--;
    }
    for(iter=myset.begin();iter!=myset.end();iter++)
    {
        cout<<(*iter).first;
    }
    cout<<myset.size();
    return 0;
}
