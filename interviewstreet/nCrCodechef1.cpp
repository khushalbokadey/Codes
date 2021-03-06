#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long Binom(long long,long long);

const long long mod=142867;

void err(vector<int> prn)

{

  for(int i=0;i<prn.size();i++)

    cerr<<prn[i]<<" ";

  cerr<<endl;

}
long long bin(long long m,long long n)

{
    vector<int> tm,tn;
    while(m)
    {

          tm.push_back(m%mod);

          m/=mod;

    }

      while(n)

        {

          tn.push_back(n%mod);

          n/=mod;

        }

      long long answer=1;

      for(int i=0;i<min(tn.size(),tm.size());i++)

        {

          answer*=Binom(tm[i],tn[i]);

          answer%=mod;

          if(answer==0)

        break;

        }

      return answer;

}
int main()

{

  int t;

  cin>>t;

  //cerr<<Binom(1008,504)<<endl;;

  for(int i=0;i<t;i++)

    {

  long long n,k;

  cin>>n>>k;
  cout<<bin(n,k)<<endl;

    }

  return 0;

}

long long gcd(long long a,long long b)

{

  if(a<b)

    swap(a,b);

  if(a%b==0)

    return b;

  else return gcd(a%b,b);

}



int inverte(int x)

{

  for(int i=1;;i++)

    {

      if((i*x%mod)==1)

	return i;

    }

}



long long Binom(long long n,long long k)

{

  if(k>n)

    return 0;

  if(k==0)

    return 1;

  if(k==n)

    return 1;

  if(k==1)

    return n%mod;

  if(k>n/2)

    return Binom(n,n-k);

  int up=1,down=1;

  for(int i=k+1;i<=n;i++)

    {

      up*=i;

      up%=mod;

    }

  for(int i=2;i<=n-k;i++)

    {

      down*=i;

      down%=mod;

    }

  if(down==1)

    return up%mod;

  down=inverte(down);

  return (up*down)%mod;

}
