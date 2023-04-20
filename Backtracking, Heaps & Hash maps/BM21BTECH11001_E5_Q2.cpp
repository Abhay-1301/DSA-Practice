#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>> &board, int n, int row, int col)
{
    // Same Column
    for (int i = row - 1; i >= 0; i--)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }
    // Upper Left Diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    // Upper Right Diagonal

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    return true;
}

void NQueen(vector<vector<char>> board, int n, int row)
{
    if (row == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int j = 0; j < n; j++)
    {

        if (isSafe(board, n, row, j))
        {
            board[row][j] = 'Q';
            NQueen(board, n, row + 1);
            board[row][j] = '.';
        }
    }
    return;
}

int main()
{
    int n = 4;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    NQueen(board, n, 0);
    return 0;
}

// Time Complexity: O(N!)
// Auxiliary Space: O(N^2)