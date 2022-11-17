#include <bits/stdc++.h>

using namespace std;

#define N 4
static int countSol = 0;

void printBoard(char board[N][N])
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    cout << "----------------------------------------------------------------\n";
    cout << "[";
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (board[i][j] == 'Q')
            {
                cout << " (" << i + 1 << ", " << j + 1 << ") ";
            }
        }
    }
    cout << "]" << endl;
    cout << "----------------------------------------------------------------\n";
}

bool isSafe(char board[N][N], int row, int col)
{
    /* Check this row on left side */
    for(int i = 0; i < row; ++i){
        if(board[i][col] == 'Q')
            return false;
    }

    /* Check upper diagonal on left side */
    for(int i = row, j = col; i >= 0 && j >= 0; --i, --j){
        if(board[i][j] == 'Q')
            return false;
    }

    /* Check lower diagonal on left side */
    for(int i = row, j = col; i >= 0 && j < N; --i, ++j){
        if(board[i][j] == 'Q')
            return 0;
    }

    return true;
}

void nqueens(char board[N][N], int row)
{
    if (row == N)
    {
        printBoard(board);
        countSol++;
        return;
    }

    for (int col = 0; col < N; ++col)
    {
        if(isSafe(board, row, col)){
            board[row][col] = 'Q';
            nqueens(board, row + 1);
            board[row][col] = '-';
        }   
    }
}

int main()
{
    char board[N][N];

    memset(board, '-', sizeof(board));

    nqueens(board, 0);

    cout << "----------------------------------------------------------------\n";
    cout << "Number of solutions for N-Queens board for N = " << N << " are: " << countSol << endl;
    cout << "----------------------------------------------------------------\n";

    return 0;
}