#include <bits/stdc++.h>
using namespace std;

bool full(vector<vector<char>> &output)
{
    for (auto i : output)
    {
        for (auto j : i)
        {
            if (j == '.')
            {
                return false;
            }
        }
    }
    return true;
}

void sudokuSolver(vector<vector<char>> &input, vector<vector<char>> &output)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (input[i][j] != '.')
            {
                output[i][j] = input[i][j];
            }
            if (input[i][j] == '.')
            {
                for (int k = 1; k <= 9; k++)
                {
                    for (int l = 0; l < 9; l++)
                    {
                        if (input[l][j] == k)
                        {
                            continue;
                        }
                        if (input[i][l] == k)
                        {
                            continue;
                        }
                        // code for if number is in grid then continue continue
                    }
                    output[i][j] = k;
                    input[i][j] = k;
                    if (full)
                    {
                        for (auto a : output)
                        {
                            for (auto j : a)
                            {
                                cout << j;
                            }
                            cout << endl;
                        }
                    }
                    sudokuSolver(input, output);
                    input[i][j] = '.';
                    output[i][j] = '.';
                }
            }
        }
    }
}

int main()
{

    return 0;
}