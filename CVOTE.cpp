#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
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
    int i , N, M, count;
    char chefname[12], country[12];
    string strchefname, strcountry, maxcountry, maxchef;

    map<string, int> chefcount;
    map<string, int> countrycount;
    map<string, string> cheftocountry;
    map<string,int>::iterator chefit , countryit;
    map<string, string>::iterator cheftocountryit;

    N = in();
    M = in();

    fr(i,N)
    {
        scanf("%s %s", chefname, country);
        strchefname = chefname;
        strcountry = country;
        cheftocountry.insert(pair<string,string>(strchefname,strcountry));
        chefcount.insert(pair<string,int>(strchefname,0));
        countrycount.insert(pair<string,int>(strcountry,0));
    }
    fr(i,M)
    {
        scanf("%s", chefname);
        strchefname = chefname;
        chefit = chefcount.find(strchefname);
        (*chefit).second++;
        cheftocountryit = cheftocountry.find(strchefname);
        countryit = countrycount.find((*cheftocountryit).second);
        (*countryit).second++;
    }
    count = 0;
    for(countryit = countrycount.begin(); countryit!= countrycount.end(); countryit++)
    {
        if((*countryit).second > count)
        {
            maxcountry = (*countryit).first;
            count = (*countryit).second;
        }

        if((*countryit).second == count)
        {
            if(maxcountry.compare((*countryit).first) > 0)
            {
                maxcountry = (*countryit).first;
            }
            count = (*countryit).second;
        }
    }
    count = 0;
    for(chefit = chefcount.begin(); chefit!= chefcount.end(); chefit++)
    {
        if((*chefit).second > count)
        {
            maxchef = (*chefit).first;
            count = (*chefit).second;
        }

        if((*chefit).second == count)
        {
            if(maxchef.compare((*chefit).first) > 0)
            {
                maxchef = (*chefit).first;
            }
            count = (*chefit).second;
        }
    }
    cout<<maxcountry<<endl<<maxchef<<endl;

    return 0;
}
