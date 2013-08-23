#include<iostream>

using namespace std;

bool issmall(int [] , int[], int);

int main()
{
    int no_of_perm, K[102], i, j;
    int output[102], temp[102];
    char matrix[102][102];

    cin>>no_of_perm;

    for(i=0;i<no_of_perm;i++)
    {
        cin>>K[i];
        output[i] = K[i];
    }


    for(i=0;i<no_of_perm;i++)
    {
        for(j=0;j<no_of_perm;j++)
        {
            cin>>matrix[i][j];
        }
    }

    for(i=0;i<no_of_perm;i++)
    {
        for(j=0;j<no_of_perm;j++)
        {
            if(matrix[i][j]=='Y')
            {
                for(int k =0;k<no_of_perm;k++)
                {
                    temp[k] = output[k];
                }
                temp[i] = output[j];
                temp[j] = output[i];
                if(issmall(output,temp, no_of_perm))
                {
                    for(int k =0;k<no_of_perm;k++)
                    {
                        output[k] = temp[k];
                    }
                    for(int k =0;k<no_of_perm;k++)
                    {
                        cout<<output[k]<<" ";
                    }
                }
            }
        }
    }

    for(i=0;i<no_of_perm;i++)
    {
        cout<<output[i]<<" ";
    }

    return 0;
}

bool issmall(int output[] , int temp[], int size)
{
    int i,j, k;
    bool flag = false;
    for(i=0;i<size;i++)
    {
        if(temp[i]<output[i])
        {
            flag = true;
            break;
        }
    }
    cout<<flag;
    return flag;
}
