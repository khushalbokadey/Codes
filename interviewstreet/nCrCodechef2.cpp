#include <stdio.h>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <time.h>
#include <fstream>
#include <sstream>
using namespace std;



long long FacMod[1010];

long long FacModInv[1010];

const long long m=142867;



long long modPow(long long a, long long x) {

    long long res = 1;

    while(x > 0) {

        if(x & 1)res = (res * a) % m;

        a = (a * a) % m;

        x >>= 1;

    }

    return res;

}

long long modInverse(long long a) {

    return modPow(a, m-2);

}



int main(void){

    int i,j,T;


    long long ans, n, k , N, K, num=1, den=1;

    FacMod[0]=FacModInv[0]=1;

    FacMod[m]=FacModInv[m]=1;

    for(i=1;i<m;i++){

        num*=i; num%=m;

        FacMod[i]=num;

        den*=modInverse(i); den%=m;

        FacModInv[i]=den;

    }



    cin>>T;

    while(T--){

        scanf("%lld %lld",&N,&K);

        ans=1;

        while(N){

            n=N%m;  k=K%m;

            if(n<k){ ans=0; break; }

            ans*=FacMod[n];

            ans*=FacModInv[k];

            ans*=FacModInv[n-k];

            ans%=m;

            N/=m;   K/=m;

        }

        printf("%lld\n",ans);

    }

    return 0;

}
