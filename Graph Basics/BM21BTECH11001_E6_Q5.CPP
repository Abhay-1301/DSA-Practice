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

void topologicalSort(vector<pair<int, int>> &pre, vector<int> &ans, unordered_map<int, list<int>> &adjList, int N)
{
    vector<int> inDegree(N, 0);
    for (auto i : pre)
    {
        createEdge(adjList, i.second, i.first, true);
        inDegree[i.first]++;
    }
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
        ans.push_back(front);
        for (auto i : adjList[front])
        {
            inDegree[i]--;
            if (inDegree[i] == 0)
                q.push(i);
        }
    }
}

int main()
{
    unordered_map<int, list<int>> adjList;
    vector<int> ans;
    vector<pair<int, int>> pre = {{1, 0}};
    int N = 2;
    topologicalSort(pre, ans, adjList, N);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}
// T.C = O(V+E) , S.C. = O(V) as it is just BFS traversal.