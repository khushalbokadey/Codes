#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>

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

bool prime[1000003];
vector <int> primes;
void generate_primes()
{
    long int limit = 1000003;
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
	for(i=0;i<1000003;i++)
	{
	    if(prime[i])
	    {
	        primes.push_back(i);
	    }
	}
}

int main()
{
    INPUT_FROM_FILE();
    int T, prime_count, prime_num, is_prime;
    long long int L, R, i, j, sqrtI, answer;
    float number;
    vector<int>::iterator it;

    generate_primes();
//    for (i=0; i<primes.size(); i++) {
//        cout << primes.at(i) << "\n";
//    }
    T = in();
    while (T--) {
        cin >> L >> R;
        answer = 0;
        for (i=L; i<=R; i++) {
            it = find(primes.begin(), primes.end(), i);
            if (*it != 0) {
                answer++;
            } else {
                sqrtI = ceil(sqrt(i));
                j = 0;
                is_prime = 1;
                while (primes.at(j) <= sqrtI) {
                    prime_count = 0;
                    number = i;
                    prime_num = primes.at(j);
                    while (ceilf(number/prime_num) == (number/prime_num) && number > 0) {
                        number /= prime_num;
                        prime_count++;
                        if (number != prime_num) {
                            it = find(primes.begin(), primes.end(), number);
                            if (*it != 0) {
                                is_prime *= 2;
                                break;
                            }
                        }
                    }
                    is_prime = is_prime * (prime_count+1);
                    j++;
                }
                it = find(primes.begin(), primes.end(), is_prime);
                if (*it != 0 || (is_prime == 1 && i != 1)) {
                    answer++;
                }
            }
            //cout<< i<< " " << is_prime << " " << answer << "\n";
        }
        cout << answer << "\n";
    }
    return 0;
}
