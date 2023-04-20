#include <bits/stdc++.h>
using namespace std;

void createEdge(unordered_map<int, list<int>> &adjList, int a, int b, bool isDirected)
{
    adjList[a].push_back(b);
    if (isDirected == false)
    {
        adjList[b].push_back(a);
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

bool isCyclicUndirected(unordered_map<int, list<int>> &adjList)
{
    unordered_map<int, bool> visited;
    for (auto i : adjList)
    {
        visited.insert({i.first, false});
    }
    unordered_map<int, int> parent;
    queue<int> q;
    int sNode = adjList.begin()->first;
    visited[sNode] = true;
    parent[sNode] = -1;
    q.push(sNode);
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto i : adjList[front])
        {
            if (visited[i] && i != parent[front])
            {
                return true;
            }
            else if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
                parent[i] = front;
            }
        }
    }
    return false;
}

bool isCyclicDirected(unordered_map<int, list<int>> &adjList, vector<int> &inDegree)
{
    int N = inDegree.size();
    int count = 0;
    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        count++;
        for (auto i : adjList[front])
        {
            inDegree[i]--;
            if (inDegree[i] == 0)
                q.push(i);
        }
    }
    return (count == N) ? false : true;
}

int main()
{
    // uncomment below code if you want to check isCyclic in UNDIRECTED graph
    // unordered_map<int, list<int>> adjList;
    // int e = 6;
    // // 0 1
    // // 0 2
    // // 2 4
    // // 4 3
    // // 3 0
    // // 2 3
    // // copy paste this in input

    // for (int i = 0; i < e; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     createEdge(adjList, u, v, false);
    // }

    // printAdjList(adjList);

    // if (isCyclicUndirected(adjList))
    //     cout << "Graph is Cyclic.\n";
    // else
    //     cout << "Graph is NOT Cyclic.\n";






    // uncomment below code if you want to check isCyclic in DIRECTED graph
    // unordered_map<int, list<int>> adjList2;
    // int e = 4;
    // int n = 4;
    // vector<int> inDegree(n, 0);
    // // 0 1
    // // 0 3
    // // 1 2
    // // 3 2
    // // copy paste this in input

    // for (int i = 0; i < e; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     createEdge(adjList2, u, v, true);
    //     inDegree[v]++;
    // }

    // printAdjList(adjList2);

    // if (isCyclicDirected(adjList2, inDegree))
    //     cout << "Graph is Cyclic.\n";
    // else
    //     cout << "Graph is NOT Cyclic.\n";

    return 0;
}

// T.C = O(V+E) , S.C. = O(V) for both algorithms as it is just BFS traversal.