#include <bits/stdc++.h>
using namespace std;

// int noOfIsland(vector<vector<int>> &grid, int &nRow, int &nColumn)
// {
//     int count = 0;
//     int tNode = nRow * nColumn;
//     vector<vector<bool>> visited(nRow, vector<bool>(nColumn, false));
//     queue<pair<int, int>> q;
//     for (int i = 0; i < nRow; i++)
//     {
//         for (int j = 0; j < nColumn; j++)
//         {
//             if (grid[i][j] == 1 && !visited[i][j])
//             {
//                 count++;
//                 q.push({i, j});
//                 visited[i][j] = true;
//                 while (!q.empty())
//                 {
//                     pair<int, int> front = q.front();
//                     q.pop();
//                     if (front.second + 1 < nColumn && grid[front.first][front.second + 1] == 1 && visited[front.first][front.second + 1] == false)
//                     {
//                         q.push({front.first, front.second + 1});
//                         visited[front.first][front.second + 1] = true;
//                     }
//                     if (front.second - 1 >= 0 && grid[front.first][front.second - 1] == 1 && visited[front.first][front.second - 1] == false)
//                     {
//                         q.push({front.first, front.second - 1});
//                         visited[front.first][front.second - 1] = true;
//                     }
//                     if (front.first + 1 < nRow && grid[front.first + 1][front.second] == 1 && visited[front.first + 1][front.second] == false)
//                     {
//                         q.push({front.first + 1, front.second});
//                         visited[front.first + 1][front.second] = true;
//                     }
//                     if (front.first - 1 >= 0 && grid[front.first - 1][front.second] == 1 && visited[front.first - 1][front.second] == false)
//                     {
//                         q.push({front.first - 1, front.second});
//                         visited[front.first - 1][front.second] = true;
//                     }
//                 }
//             }
//         }
//     }
//     return count;
// }

int noOfIslandDFS(vector<vector<int>> &grid, int &nRow, int &nColumn,vector<vector<bool>> &visited,int &count)
{
    int tNode = nRow * nColumn;
    for (int i = 0; i < nRow; i++)
    {
        for (int j = 0; j < nColumn; j++)
        {
            if (grid[i][j] == 1 && !visited[i][j])
            {
                count++;
                visited[i][j] = true;
                pair<int,int> front = {i,j};
                    if (front.second + 1 < nColumn && grid[front.first][front.second + 1] == 1 && visited[front.first][front.second + 1] == false)
                    {
                        visited[front.first][front.second + 1] = true;
                        noOfIslandDFS(grid,nRow,nColumn,visited,count);
                    }
                    if (front.second - 1 >= 0 && grid[front.first][front.second - 1] == 1 && visited[front.first][front.second - 1] == false)
                    {
                        visited[front.first][front.second - 1] = true;
                        noOfIslandDFS(grid,nRow,nColumn,visited,count);
                    }
                    if (front.first + 1 < nRow && grid[front.first + 1][front.second] == 1 && visited[front.first + 1][front.second] == false)
                    {
                        visited[front.first + 1][front.second] = true;
                        noOfIslandDFS(grid,nRow,nColumn,visited,count);
                    }
                    if (front.first - 1 >= 0 && grid[front.first - 1][front.second] == 1 && visited[front.first - 1][front.second] == false)
                    {
                        visited[front.first - 1][front.second] = true;
                        noOfIslandDFS(grid,nRow,nColumn,visited,count);
                    }
                
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> grid = {{1, 1, 1, 1, 0},
                                {1, 1, 0, 1, 0},
                                {1, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0}};
    int nRow = 4;
    int nColumn = 5;
    // cout << noOfIsland(grid, nRow, nColumn);

    vector<vector<bool>> visited(nRow, vector<bool>(nColumn, false));
    int count = 0;
    cout << noOfIslandDFS(grid, nRow, nColumn,visited,count);
    return 0;
}

// T.C = O(row*column) or O(V)
// S.C = O(row*column) or O(V) {visited matrix}