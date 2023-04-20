#include <bits/stdc++.h>
using namespace std;

void BFS(unordered_map<int, list<int>> adjList, int sNode, int N)
{
    bool visited[N];
    queue<int> q;
    q.push(sNode);
    visited[sNode] = true;
    while (!q.empty())
    {
        int front = q.front();
        cout << front << " ";
        q.pop();
        for (auto i : adjList[front])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

// void DFS(unordered_map<int, list<int>> adjList, int sNode)
// {
//     unordered_map<int, bool> visited;
//     stack<int> st;
//     st.push(sNode);
//     for (auto i : adjList)
//     {
//         visited[i.first] = false;
//     }
//     while (!st.empty())
//     {
//         int front = st.top();
//         cout << front << " ";
//         visited[front] = true;
//         st.pop();
//         for (auto i : adjList[front])
//         {
//             if (!visited[i])
//             {
//                 st.push(i);
//             }
//         }
//     }
// }

void DFS_Recursive(unordered_map<int, list<int>> &adjList, int sNode, vector<bool> &visited)
{
    cout << sNode << " ";
    visited[sNode] = true;
    for (auto i : adjList[sNode])
    {
        if (!visited[i])
        {
            DFS_Recursive(adjList, i, visited);
        }
    }
}

// Assuming that there are total N nodes from 0 to N-1
void BFS_by_Matrix(vector<vector<int>> &adjMat, int sNode, int N)
{
    bool visited[N];
    queue<int> q;
    q.push(sNode);
    for (int i = 0; i < N; i++)
    {
        visited[i] = 0;
    }
    visited[sNode] = 1;
    while (!q.empty())
    {
        int k = -1;
        int front = q.front();
        cout << front << " ";
        q.pop();
        for (auto i : adjMat[front])
        {
            k++;
            if (i == 1)
            {
                if (!visited[k])
                {
                    q.push(k);
                    visited[k] = 1;
                }
            }
        }
    }
}

void DFS_by_Matrix(vector<vector<int>> &adjMat, int sNode, vector<bool> &visited, int N)
{
    cout << sNode << " ";
    visited[sNode] = true;
    for (int i = 0; i < N; i++)
    {
        if (adjMat[sNode][i] == 1 && !visited[i])
        {
            DFS_by_Matrix(adjMat, i, visited, N);
        }
    }
}

int main()
{
    int N = 11;
    vector<bool> visited(N, false);
    vector<vector<int>> v = {

        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}};

    DFS_by_Matrix(v, 1, visited, N);
    return 0;
}