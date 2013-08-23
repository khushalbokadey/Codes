#include<iostream>
using namespace std;

/** this is the size of chess board */
int N;

void print_solution(int state[80][80]);
bool accept(int state[80][80], int row, int col);
void solve_state(int state[80][80], int row);

int main()
{
    cin>>N;
    /* initialise the board */
    int state[80][80] = {0};

    solve_state (state, 0);

    return 0;
}


/** Given a completed board, this prints it to the stdout */
void print_solution(int state[80][80])
{
    int i,j;
    for(i=0; i<N; ++i)
    {
        for(j=0; j<N; ++j)
        {
            if(state[i][j]==1)
            {
                if(j==0)
                {
                    cout<<10<<" ";
                }
                else
                {
                    cout<<j<<" ";
                }
            }
        }
            //cout<<state[i][j]<<" ";
        //cout<<endl;
    }
    cout<<endl;
}

/** return true if placing a queen on [row][col] is acceptable
else return false */
bool accept(int state[80][80], int row, int col)
{
    int i,j;

    /* check the column */
    for (i=0; i<N; ++i)
    {
        if (state[row][i])
        return false;
    }

    /* check the row */
    for (i=0; i<N; ++i)
    {
        if (state[i][col])
        return false;
    }

    /* check the upper left diagnol */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (state[i][j])
        return false;
    }

    /* check the lower left diagnol */
    for (i = row, j = col; i < N && j >= 0; ++i, --j)
    {
        if (state[i][j])
        return false;
    }

    /* check the upper right diagnol */
    for (i = row, j = col; i >= 0 && j < N; i--, ++j)
    {
        if (state[i][j])
        return false;
    }

    /* check the lower right diagnol */
    for (i = row, j = col; i < N && j < N; ++i, ++j)
    {
        if (state[i][j])
            return false;
    }

    /*Knight condition 1*/
    if(row+2<=N && j+1<=N)
    {
        if (state[row+2][j+1])
            return false;
    }

    /*Knight condition 2*/
    if(j-1>=0 && row+2<=N)
    {
        if (state[row+2][j-1])
        return false;
    }

    /*Knight condition 3*/
    if(row+1<=N && j+2<=N)
    {
        if (state[row+1][j+2])
            return false;
    }

    /*Knight condition 4*/
    if(row+1<=N && j-2>=0)
    {
        if (state[row+1][j-2])
            return false;
    }

    /*Knight condition 5*/
    if(j+2<=N && row-1>=0)
    {
        if (state[j+2][row-1])
            return false;
    }

    /*Knight condition 6*/
    if(row-2>=0 && j+1<=N)
    {
        if (state[j+2][row-2])
        return false;
    }

    /*Knight condition 7*/
    if(row-1>=0 && j-2>=0)
    {
        if (state[row+1][j+2])
            return false;
    }

    /*Knight condition 8*/
    if(row-2>=0 && j-1>=0)
    {
        if (state[row+1][j-2])
            return false;
    }

    /* return true if all tests passed */
    return true;
}

void solve_state(int state[80][80], int row)
{
    int i;

    /* if all queens have been placed at non conflicting positions */
    if (row == N)
    {
        print_solution(state);
        return;
    }

    /* Place queens on all positions in a given row and
    check if the state is acceptable
    Continue the process till all possibilities found */
    for(i=0; i<N; ++i)
    {
        if(accept(state, row, i))
        {
            state[row][i] = 1;
            solve_state(state, row+1);
        }
        state[row][i] = 0;
    }
}
