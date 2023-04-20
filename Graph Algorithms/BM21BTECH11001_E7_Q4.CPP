#include <bits/stdc++.h>
using namespace std;

void makeSet(vector<int> &parent, vector<int> &rank, int N)
{
    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(vector<int> &parent, vector<int> &rank, int u, int v)
{
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

// T.C=O(E.logN)
// S.C=O(N+E)
int MSTbyKRUSKAL(vector<vector<int>> &edges, int n)
{
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);
    int minWeight = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int weight = edges[i][2];
        if (u != v)
        {
            minWeight += weight;
            unionSet(parent, rank, u, v);
        }
    }
    return minWeight;
}

// T.C=O(E.logN)
// S.C=O(N)
void MSTbyPRIMS(unordered_map<int, list<pair<int, int>>> &adjList, int N, int sNode)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> parent(N, -1);
    vector<int> key(N, INT_MAX);
    vector<bool> inMST(N, false);

    key[sNode] = 0;
    pq.push({sNode, 0});

    for (int i = 0; i < N - 1; i++)
    {
        int front = pq.top().second;
        pq.pop();
        inMST[front] = true;
        for (auto it : adjList[front])
        {
            int node = it.first;
            int wt = it.second;
            if (inMST[node] == false && wt < key[node])
            {
                parent[node] = front;
                pq.push({key[node], node});
                key[node] = wt;
            }
        }
    }
    for (int i = 1; i < N; i++)
        cout << parent[i] << " - " << i << endl;
}

int main()
{

    return 0;
}