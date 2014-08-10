#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<cmath>
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
char num[100002];
int flag;
void getNextPalin() {
    int len, i, flag = 1, x, j = 0;
	len = strlen(num);
	for(i = 0; i < len; i++) {
		if (num[i] != '9') {
			flag = 0;
			break;
		}
	}

	if (flag == 1)
	{
		num[0] = '1';
		for(i = 1; i < len; i++)
		{
			num[i] = '0';
		}
		num[len] = '1';
		num[len + 1] = '\0';
		return;
	}

	flag = 0;
	for(i = 0; i < (len / 2); i++)
	{
		if(num[i] < num[len - 1 - i])
		flag = -1;
		else if(num[i] > num[len - 1 - i])
		flag = 1;
		num[len - 1 - i] = num[i];
	}

	if(flag == -1 || flag == 0)
	{
		if(len % 2 == 0)
		x = (len / 2) - 1;
		else
		x = len / 2;
		while(num[x - j] == '9')
		{
			num[x - j] = '0';
			num[len - 1 - x + j] = '0';
			j++;
		}
		num[x - j]++;
		num[len - 1 - x + j] = num[x - j];
	}
	return;
}

int main()
{
    INPUT_FROM_FILE();
    gets(num);
    getNextPalin();
    cout << num << "\n";
    return 0;
}
