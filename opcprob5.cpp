#include<list>
#include<vector>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>

using namespace std;

class TitleString
{

    public:
        string toFirstUpperCase(string title)
        {
            if(isalpha(title[0]))
                title[0] = toupper(title[0]);
            for (int i =0 ; i<title.size();i++)
            {
                if(isalpha(title[i]) && !isalpha(title[i-1]))
                    title[i] = toupper(title[i]);
            }
            return title;
        }
};

int main()
{
    TitleString obj;
    cout<<obj.toFirstUpperCase("intro to algorithms");
    return 0;
}
