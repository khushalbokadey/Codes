#include<iostream>
#include<string>

using namespace std;

int main()
{
    long N , i;
    struct data words[300000];
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin.getline (words[i].arr,20);
    }
    return 0;
}
