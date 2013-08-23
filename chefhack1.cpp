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
    //freopen("output.txt","w",stdout);
    #endif
}
bool prime[10000000];
int primes[(10000000/2)+1];
int primecount[10000000];
int server[351][351];

void generate_primes()
{
    int limit = 10000000;
	int root = ceil(sqrt(limit));
	int insert = 2;
	primes[0] = 2;
	primes[1] = 3;
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

void makezero(int count[][351], int n)
{
    int i, j, k;

    fr(i,n)
    {
        fr(j,n)
        {
            if(count[i][j]>=0)
            {
                k = j;
                while((k<n-1) && (count[i][k+1]<0) && ((server[i][k]==1 && server[i][k+1]==1) || (server[i][k]==2 && server[i][k+1]==2)))
                {
                    count[i][k+1] = 0;
                    k++;
                }

                k = i;
                while((k<n-1) && (count[k+1][j]<0) && ((server[k][j]==1 && server[k+1][j]==1) || (server[k][j]==2 && server[k+1][j]==2)))
                {
                    count[k+1][j] = 0;
                    k++;
                }

                k = j;
                while((k>0) && (count[i][k-1]<0) && ((server[i][k]==1 && server[i][k-1]==1) || (server[i][k]==2 && server[i][k-1]==2)))
                {
                    count[i][k-1] = 0;
                    k--;
                }

                k = i;
                while((k>0) && (count[k-1][j]<0) && ((server[k][j]==1 && server[k-1][j]==1) || (server[k][j]==2 && server[k-1][j]==2)))
                {
                    count[k-1][j] = 0;
                    k--;
                }
            }
        }
    }
}

int main()
{
    INPUT_FROM_FILE();
    int no_of_test, i , n, j, tempcount, totalcount , k , l;
    int pass[351][351], count[351][351];

    generate_primes();
    prime[2] = prime[3] = true;

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
        fill(&count[0][0], &count[351][0], -1);
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
                if(count[i][j]<0)
                {
                    if(server[i][j]==1)
                    {
                        count[i][j] = (pass[i][j]/2);
                        makezero(count, n);
                    }
                    else if(server[i][j] == 2)
                    {
                        if(pass[i][j]!=1)
                        {
                            count[i][j] = (pass[i][j]/2 + 2);
                        }
                        else
                        {
                            count[i][j] = 0;
                        }
                        makezero(count, n);
                    }
                    else if(server[i][j] == 3)
                    {
                        count[i][j] = primecount[pass[i][j]];
                    }
                }

                /*fr(k,n)
                {
                    fr(l,n)
                    {
                        cout<<count[k][l]<<" ";
                    }
                    cout<<endl;
                }
                cout<<endl;*/

            }
        }
        fr(i,n)
        {
            fr(j,n)
            {
                totalcount += count[i][j];
            }
        }

        cout<<totalcount<<endl;
    }

    return 0;
}
