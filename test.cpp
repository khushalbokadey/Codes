#include<stdio.h>
#include<map>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
	int i,k,cas,flag1,flag2;
	map<char,int>mp1;
	map<char,int>mp2;
	map<char,int>::iterator it;
	char s1[1005],s2[1005];
	scanf("%d",&cas);
	while(cas--)
	{
		mp1.clear();
		mp2.clear();
		scanf("%s %s",s1,s2);
		int len=strlen(s1);
		for(i=0;i<len;i++)
			mp1[s1[i]]++;
		len=strlen(s2);
		for(i=0;i<len;i++)
			mp2[s2[i]]++;
		flag1=flag2=0;
		for ( it=mp1.begin() ; it != mp1.end(); it++ )
            cout << (*it).first << " => " << (*it).second << endl;
        for ( it=mp2.begin() ; it != mp2.end(); it++ )
            cout << (*it).first << " => " << (*it).second << endl;
		for(i='a';i<='z';i++)
		{

              if(mp1.find(i)==mp1.end()&&mp2.find(i)==mp2.end()) continue;
			  else if((mp1.find(i)==mp1.end()&&mp2.find(i)!=mp2.end())||(mp1.find(i)!=mp1.end()&&mp2.find(i)==mp2.end()))
			  {flag1=1;break;}//flag1
			  else
			  {
				  if(mp1[i]!=mp2[i])  {flag2=1;}//flag2
			  }
		}cout<<endl;
		if(flag1==1) printf("YES\n");
		else if(flag2==0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
