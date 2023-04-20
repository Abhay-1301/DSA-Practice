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

int Degree(unordered_map<int, list<int>> &adjList, int node)
{
    return adjList[node].size();
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
    int tNodes = 5;
    int tEdges = 7;
    unordered_map<int, list<int>> adjList;
    vector<vector<int>> adjMat(tNodes, vector<int>(tNodes, 0));

    createEdge(adjMat, adjList, 0, 1, false);
    createEdge(adjMat, adjList, 2, 1, false);
    createEdge(adjMat, adjList, 4, 1, false);
    createEdge(adjMat, adjList, 0, 3, false);
    createEdge(adjMat, adjList, 0, 4, false);
    createEdge(adjMat, adjList, 3, 1, false);
    createEdge(adjMat, adjList, 4, 3, false);

    cout << "Adjoint Matrix of graph is : \n";
    printAdjMatrix(adjMat);
    cout << "Adjoint List of graph is : \n";
    printAdjList(adjList);
    cout << "BFS Traversal of graph starting from node 0 is : \n";
    BFS_by_Matrix(adjMat, 0, tNodes); // BFS starting from 0
    cout << "\nDegree of each node is : \n";
    cout << "0 -> " << Degree(adjList, 0) << endl;
    cout << "1 -> " << Degree(adjList, 1) << endl;
    cout << "2 -> " << Degree(adjList, 2) << endl;
    cout << "3 -> " << Degree(adjList, 3) << endl;
    cout << "4 -> " << Degree(adjList, 4) << endl;
    return 0;
}

// The Time complexity of BFS and DFS both is O(V + E) when Adjacency List is used and O(V^2) when Adjacency Matrix is used.
// S.C = O(V)