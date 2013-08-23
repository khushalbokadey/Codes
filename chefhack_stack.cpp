#include<iostream>
#include<string.h>
#include<stdio.h>
#include<cmath>
#include<string>
#include<algorithm>
#include <stack>

using namespace std;

#define in() ({ int x; scanf("%d", &x); x; })
#define fr(i,n) for(i = 0; i < n; i++)

void INPUT_FROM_FILE()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
}
bool prime[10000000];
long int primecount[10000000];
long int  server[351][351];

void generate_primes()
{
    long int limit = 10000000;
	long int root = ceil(sqrt(limit));
	int insert = 2;
	for (int z = 0; z < limit; z++)
	{
	    prime[z] = false;
	}
	for (int x = 1; x <= root; x++)
	{
		for (int y = 1; y <= root; y++)
		{
			int n = (4*x*x)+(y*y);
			if (n <= limit && (n % 12 == 1 || n % 12 == 5)) prime[n] ^= true;
			n = (3*x*x)+(y*y);
			if (n <= limit && n % 12 == 7) prime[n] ^= true;
			n = (3*x*x)-(y*y);
			if (x > y && n <= limit && n % 12 == 11) prime[n] ^= true;
		}
	}
	prime[2] = prime[3] = true;
	for (int r = 5; r <= root; r++)
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

int main()
{
    INPUT_FROM_FILE();
    long int no_of_test, i , n, j, tempcount, totalcount , k , l, b;
    long int pass[351][351], counts[351][351];
    stack<long int> indexstack;

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
                    }
                    else if(server[i][j] == 2)
                    {
                        counts[i][j] = (pass[i][j]/2 + 2);
                    }
                    else if(server[i][j] == 3)
                    {
                        counts[i][j] = primecount[pass[i][j]];
                    }

                    while (!indexstack.empty())
                    {
                         indexstack.pop();
                    }
                    indexstack.push(i*n + j);

                    while(!indexstack.empty())
                    {
                        b = indexstack.top();
                        indexstack.pop();
                        k = i; l = j;
                        i = b / n;
                        j = b % n;
                        if( (i <= n-2) && ( (server[i][j] == 1 && server[i+1][j]==1) || (server[i][j]==2 && server[i+1][j]==2) ) && (counts[i+1][j]<0) )
                        {
                            counts[i+1][j] = 0;
                            indexstack.push((i+1)*n + j);
                        }
                        if( (j <= n-2) && (counts[i][j+1]<0) && ( (server[i][j] == 1 && server[i][j+1]==1) || (server[i][j]==2 && server[i][j+1]==2) ) )
                        {
                            counts[i][j+1] = 0;
                            indexstack.push(i*n + j + 1);
                        }
                        if( (i >= 1) && (counts[i-1][j]<0) && ( (server[i][j] == 1 && server[i-1][j]==1) || (server[i][j]==2 && server[i-1][j]==2) ) )
                        {
                            counts[i-1][j] = 0;
                            indexstack.push((i-1)*n + j);
                        }
                        if( (j >= 1) && (counts[i][j-1]<0) && ( (server[i][j] == 1 && server[i][j-1]==1) || (server[i][j]==2 && server[i][j-1]==2) ) )
                        {
                            counts[i][j-1] = 0;
                            indexstack.push(i*n + j-1);
                        }
                        i = k; j = l;
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
