#include <map>
#include <set>
#include <list>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}



/* Head ends here */
void printTransactions(double m, int k, int d, vector <string> name, vector <int> owned, vector < vector <double> > prices)
{
    //Enter your code here
    int i, j, limit;
    int low;
    low = 0;

    for(j=1;j<k;j++)
    {
        if(prices.at(low).at(4))>prices.at(j).at(4)))
    }
    for(i=0;i<k;i++)
    {
        cout<<"2\n";
    }
}

/* Tail starts here */
int main()
{
    INPUT_FROM_FILE();
    double _m;
    cin >> _m;

    int _k;
    cin >> _k;

    int _d;
    cin >> _d;

    vector<string> _name;
    vector<int> _owned;
    vector < vector <double> > _prices;

    string _name_item;
    int _owned_item;
    double _prices_item_item;

    for(int _i=0; _i<_k; _i++)
    {
        cin >> _name_item;
        _name.push_back(_name_item);

        cin >> _owned_item;
        _owned.push_back(_owned_item);

        vector <double> _prices_item;
        for(int _j = 0; _j<5; _j++) {
            cin >> _prices_item_item;
            _prices_item.push_back(_prices_item_item);
        }
        _prices.push_back(_prices_item);

    }

    printTransactions(_m, _k, _d, _name, _owned, _prices);

    return 0;
}
