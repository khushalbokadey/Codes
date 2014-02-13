#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>
#include<fstream>
#include <locale>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 0; i < n; i++)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    //freopen("names.txt", "r", stdin);
    freopen("newop.txt", "w", stdout);
    #endif
}
string toLower(string strr)
{
	char str[100];
	string ret;
	strcpy(str,strr.c_str());
	int differ = 'A'-'a';
	char ch;
	int ii = strlen(str);
	for (int i=0; i <ii;i++)
	{
		strncpy(&ch,str+i,1);
		if (ch>='A' && ch<='Z')
		{
			ch = ch-differ;
			memcpy(str+i,&ch,1);
		}
	}
	ret = str;
	return ret;
}

int main()
{
    INPUT_FROM_FILE();
    int i;
    ifstream iFile("count.rtf");
    std::locale loc;
    i=0;
    while (!iFile.eof())
    {
    	string str;
        iFile >> str;
        char chars[] = "()',";
        for (unsigned int i = 0; i < strlen(chars); ++i)
        {
            str.erase (std::remove(str.begin(), str.end(), chars[i]), str.end());
        }
        cout<<'"' << toLower(str) <<'"' << ", ";
    }
    return 0;
}
