#include<iostream>

using namespace std;
int main()
{
	int i,j,t,r,f=0,c;
	char a[100][100];
	char ch;
	cin>>t;
	while(t--)
	{
		cin>>r>>c;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				cin>>ch;
				if((ch>=65)&&(ch<=90))
				{
					ch=ch+32;
				}
				a[i][j]=ch;
			}
		}
		for(i=0;i<r;i++)
		{
			for(j=0;j<c-4;j++)
			{
				if(a[i][j]=='s' && a[i][j+1]=='p' && a[i][j+2]=='o' && a[i][j+3]=='o' && a[i][j+4]=='n')
				{
					f=1;
					break;
				}
			}
		}
		for(i=0;i<r-4;i++)
		{
			for(j=0;j<c;j++)
			{
				if(a[i][j]=='s' && a[i+1][j]=='p' && a[i+2][j]=='o' && a[i+3][j]=='o' && a[i+4][j]=='n')
				{
					f=1;
					break;
				}
			}
		}
		if(f==1)
		{
		cout<<"There is a spoon!\n";
		}
		else
		{
		cout<<"There is indeed no spoon!\n";
		}
		f=0;

	}

	}
