#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<vector>
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

int main()
{
    INPUT_FROM_FILE();
    int N, i, j, Bcount, Wcount, colindex, colcount;
    char arr[51][51], basecolor;
    vector< vector<int> > output;
    output.resize( 0 , vector<int>( 0 , 0 ) );

    N = in();
    Bcount = Wcount = 0;

    fr(i,N)
    {
        fr(j,N)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='B')
                Bcount++;
            else
                Wcount++;
        }
    }

    if(Bcount>=Wcount)
    {
        int temparr[] = {0,0,N-1,N-1,66};
        basecolor = 'B';
        vector<int> temp (temparr, temparr+5);
        output.push_back(temp);
    }
    else
    {
        int temparr[] = {0,0,N-1,N-1,87};
        basecolor = 'W';
        vector<int> temp (temparr, temparr+5);
        output.push_back(temp);
    }

    for(i=0;i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            if(arr[i][j] != basecolor)
            {
                colindex = j;
                colcount = j;
                char ch = basecolor == 'B' ? 'W' : 'B';
                while(arr[i][j] == ch)
                {
                    colcount++;
                    j++;
                }
                int temparr[] = {i,colindex, i, --colcount, (int)ch};
                vector<int> temp (temparr, temparr+5);
                output.push_back(temp);
            }
        }
    }

    int len = output.size();
    cout<<len<<endl;

    for(i=0; i<len; i++)
    {
        for(j=0; j<5; j++)
        {
            if(j!=4)
                cout<<output[i][j]<<" ";
            else
                cout<<(char)output[i][j];
        }
        cout<<endl;
    }

    return 0;
}
