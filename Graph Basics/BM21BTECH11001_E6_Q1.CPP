#include <bits/stdc++.h>
using namespace std;

void createEdge(vector<vector<int>> &adjMat, unordered_map<int, list<int>> &adjList, int a, int b, bool directed)
{
    adjList[a].push_back(b);
    adjMat[a][b] = 1;
    if (directed == false)
    {
        adjList[b].push_back(a);
        adjMat[b][a] = 1;
    }
}

void printAdjMatrix(vector<vector<int>> &adjMat)
{
    for (auto i : adjMat)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void printAdjList(unordered_map<int, list<int>> &adjList)
{
    for (auto i : adjList)
    {
        cout << i.first << " -> ";
        for (auto j : i.second)
        {
            cout << j;
            cout << "-";
        }
        cout << endl;
    }
}

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

void DFS_Iterative(unordered_map<int, list<int>> adjList, int sNode)
{
    unordered_map<int, bool> visited;
    stack<int> st;
    st.push(sNode);
    for (auto i : adjList)
    {
        visited[i.first] = false;
    }
    while (!st.empty())
    {
        int front = st.top();
        cout << front << " ";
        visited[front] = true;
        st.pop();
        for (auto i : adjList[front])
        {
            if (!visited[i])
            {
                st.push(i);
            }
        }
    }
}

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
    int tNodes;
    int tEdges;
    unordered_map<int, list<int>> adjList;
    vector<vector<int>> adjMat(tNodes, vector<int>(tNodes, 0));

    for (int i = 0; i < tEdges; i++)
    {
        int u, v;
        cin >> u >> v;
        createEdge(adjMat, adjList, u, v, false);
    }

    return 0;
}

// The Time complexity of BFS and DFS both is O(V + E) when Adjacency List is used and O(V^2) when Adjacency Matrix is used.
// S.C = O(V)