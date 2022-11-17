// N-QUEENS USING BACKTRACKING

#include <bits/stdc++.h>

using namespace std;

#define N 4
static int countSol = 0;

void printBoard(char board[N][N]){
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    cout << "[ ";
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(board[i][j] == 'Q')
                cout << j + 1 << ", ";
        }
    }

    cout << "]" << endl;;
}

bool isSafe(char board[N][N], int row, int col){
    int x = row;
    int y = col;

    while(y >= 0){
        if(board[x][y] == 'Q')
            return false;
        y--;
    }

    x = row;
    y = col;

    while(x >= 0 && y >= 0){
        if(board[x][y] == 'Q')
            return false;
        x--;
        y--;
    }

    x = row;
    y = col;

    while(x < N && y >= 0){
        if(board[x][y] == 'Q')
            return false;
        x++;
        y--;
    }

    return true;
}

void nqueens(char board[N][N], int col){
    if(col == N){
        printBoard(board);
        countSol++;
        return;
    }

    for(int row = 0; row < N; ++row){
        if(isSafe(board, row, col)){
            board[row][col] = 'Q';
            nqueens(board, col + 1);
            board[row][col] = '-';
        }
    }
}

int main(){
    char board[N][N];

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            board[i][j] = '-';
        }
    }

    nqueens(board, 0);

    cout << "Number of solutions for N = " << N << " is : " << countSol << endl;

    return 0;
}