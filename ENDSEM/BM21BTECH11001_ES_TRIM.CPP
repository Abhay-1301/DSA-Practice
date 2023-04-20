#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        unordered_map<int, list<int>> adjList;
        for (auto i : edges)
        {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
        }
        vector<int> ans;
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
                    ans = {i, front};
                    return ans;
                }
                else if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                    parent[i] = front;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution S;
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {4, 3},{1,4},{1,5}};
    vector<int> ans = S.findRedundantConnection(edges);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}