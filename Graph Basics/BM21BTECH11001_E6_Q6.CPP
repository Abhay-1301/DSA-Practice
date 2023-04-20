#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

void dfs(vector<vector<int>> &input, int node, vector<bool> &visited, stack<int> &TS, int N)
{
    visited[node] = true;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            dfs(input, i, visited, TS, N);
        }
    }
    TS.push(node);
}

vector<int> shortestPathBwTwoPoints(int sNode, vector<vector<int>> &input, stack<int> &TS, int N)
{
    stack<int> st = TS;
    vector<int> dist(N, INF);
    dist[sNode] = 0;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if (dist[top] != INF)
        {
            for (int i = 0; i < N; i++)
            {
                if (input[top][i] != INF)
                {
                    if (dist[i] > input[top][i] + dist[top])
                        dist[i] = input[top][i] + dist[top];
                }
            }
        }
    }
    return dist;
}

void shortestPath(vector<vector<int>> &input, vector<vector<int>> &output, int N)
{
    stack<int> TS;
    vector<bool> visited(N, false);
    dfs(input, 0, visited, TS, N);
    for (int i = 0; i < N; i++)
    {
        output[i] = shortestPathBwTwoPoints(i, input, TS, N);
    }
}

int main()
{
    int N = 4;
    vector<vector<int>> input = {{0, 5, INF, 10},
                                 {INF, 0, 3, INF},
                                 {INF, INF, 0, 1},
                                 {INF, INF, INF, 0}};
    vector<vector<int>> output(N, vector<int>(N, INF));

    shortestPath(input, output, N);
    for (auto i : output)
    {
        for (auto j : i)
        {
            if (j == INF)
            {
                cout << "I ";
            }
            else
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// T.C = O(N+E)
// S.C = O(N+E)