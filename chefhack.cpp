#include<iostream>
#include<string.h>
#include<stdio.h>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 0; i < n; i++)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
}
bool prime[10000000];
long long int primecount[10000000];
long long int  server[351][351], counts[351][351];

void generate_primes()
{
    long long int limit = 10000000;
	long long int root = ceil(sqrt(limit));
	int insert = 2;
	for (long long int z = 0; z < limit; z++)
	{
	    prime[z] = false;
	}
	for (long long int x = 1; x <= root; x++)
	{
		for (long long int y = 1; y <= root; y++)
		{
			long long int n = (4*x*x)+(y*y);
			if (n <= limit && (n % 12 == 1 || n % 12 == 5)) prime[n] ^= true;
			n = (3*x*x)+(y*y);
			if (n <= limit && n % 12 == 7) prime[n] ^= true;
			n = (3*x*x)-(y*y);
			if (x > y && n <= limit && n % 12 == 11) prime[n] ^= true;
		}
	}
	prime[2] = prime[3] = true;
	for (long long int r = 5; r <= root; r++)
	{
	    if (prime[r])
	    {
	        for (int i = r*r; i < limit; i += r*r)
	        {
	            prime[i] = false;
            }
	    }
	}
}

void makezero(int i, int j, int n)
{
    if( (j>0) && (counts[i][j-1]<0) && ( (server[i][j] == 1 && server[i][j-1]==1) || (server[i][j]==2 && server[i][j-1]==2) ) )
    {
        counts[i][j-1] = 0;
        makezero(i,j-1,n);
    }

    if( (i>0) && (counts[i-1][j]<0) && ( (server[i][j] == 1 && server[i-1][j]==1) || (server[i][j]==2 && server[i-1][j]==2) ) )
    {
        counts[i-1][j] = 0;
        makezero(i-1,j,n);
    }

    if( (j<n-1) && (counts[i][j+1]<0) && ( (server[i][j] == 1 && server[i][j+1]==1) || (server[i][j]==2 && server[i][j+1]==2) ) )
    {
        counts[i][j+1] = 0;
        makezero(i,j+1,n);
    }

    if( (i<n-1) && (counts[i+1][j]<0) && ( (server[i][j] == 1 && server[i+1][j]==1) || (server[i][j]==2 && server[i+1][j]==2) ) )
    {
        counts[i+1][j] = 0;
        makezero(i+1,j,n);
    }
}

int main()
{
    INPUT_FROM_FILE();
    long long int no_of_test, i , n, j, tempcount , k , l;
    long long int totalcount;
    int pass[351][351];

    generate_primes();
    tempcount=0;
    fr(i,10000000)
    {
        if(prime[i])
        {
            primecount[i] = tempcount;
            tempcount++;
        }
    }

    no_of_test = in();

    while(no_of_test--)
    {
        n = in();
        totalcount = 0;
        fill(&counts[0][0], &counts[351][0], -1);
        fill(&server[0][0], &server[351][0], 0);
        fr(i,n)
        {
            fr(j,n)
            {
                pass[i][j] = in();

                if(prime[pass[i][j]])
                {
                    server[i][j] = 3;
                }
                else if(pass[i][j]%2==0)
                {
                    server[i][j] = 1;
                }
                else
                {
                    server[i][j] = 2;
                }
            }
        }
        fr(i,n)
        {
            fr(j,n)
            {
                if(counts[i][j]<0)
                {
                    if(server[i][j]==1)
                    {
                        counts[i][j] = (pass[i][j]/2);
                        makezero(i,j,n);
                    }
                    else if(server[i][j] == 2)
                    {
                        counts[i][j] = (pass[i][j]/2 + 2);
                        makezero(i,j,n);
                    }
                    else if(server[i][j] == 3)
                    {
                        counts[i][j] = primecount[pass[i][j]];
                    }
                }
            }
        }
        fr(i,n)
        {
            fr(j,n)
            {
                totalcount += counts[i][j];
            }
        }

        cout<<totalcount<<endl;
    }

    return 0;
}
