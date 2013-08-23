#include<iostream>
#include<string.h>
#include<stdio.h>
#include <cmath>
#include<string>
#include<algorithm>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 0; i < n; i++)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
bool prime[100000];
int primes[10000];

void generate_primes()
{
    long int limit = 100000;
	long int root = ceil(sqrt(limit));
	long int i, x, y, z, r;
	for (z = 0; z < limit; z++)
	{
	    prime[z] = false;
	}
	for (x = 1; x <= root; x++)
	{
		for (y = 1; y <= root; y++)
		{
			int n = (4*x*x)+(y*y);
			if (n <= limit && (n % 12 == 1 || n % 12 == 5))
			{
			    prime[n] ^= true;
			}
			n = (3*x*x)+(y*y);
			if (n <= limit && n % 12 == 7)
			{
                prime[n] ^= true;
			}
			n = (3*x*x)-(y*y);
			if (x > y && n <= limit && n % 12 == 11)
			{
                prime[n] ^= true;
			}
		}
	}
	prime[2] = true;
	prime[3] = true;
	int a = 0;
	for (r = 5; r <= root; r++)
	{
	    if (prime[r])
	    {
	        for (i = r*r; i < limit; i += r*r)
	        {
	            prime[i] = false;
            }
	    }
	}
	for(i=0;i<100000;i++)
	{
	    if(prime[i])
	    {
	        primes[a++] = i;
	    }
	}
}

int main()
{
    INPUT_FROM_FILE();
    long long int no_of_test, i, j, m, n, sqrti;
    bool flag;

    generate_primes();

    no_of_test = in();
    while(no_of_test--)
    {
        m = in();
        n = in();
        for(i=m; i<=n;i++)
        {
            flag = false;
            if(i%6==1 || i%6==5)
            {
                flag = true;
                sqrti = sqrt(i);
                j=0;
                while(primes[j]<=sqrti)
                {
                    if(i%primes[j]==0)
                    {
                        flag=false;
                        break;
                    }
                    j++;
                }
            }
            else if(i==2 || i==3)
            {
                flag = true;
            }
            if(flag)
            {
                cout<<i<<endl;
            }
        }
        cout<<endl;
    }

    return 0;
}
