#include <bits/stdc++.h>
using namespace std;

int minSignalTime(vector<vector<int>> &times, int N, int K)
{
    unordered_map<int, list<pair<int, int>>> adjList;
    for (int i = 0; i < times.size(); i++)
    {
        pair<int, int> p;
        p.first = times[i][1];
        p.second = times[i][2];
        adjList[times[i][0]].push_back(p);
    }
    pair<int, int> p;
    p.first = K;
    p.second = 0;
    queue<pair<int, int>> q;
    q.push(p);

    vector<int> dist(N + 1, INT_MAX);
    dist[K] = 0;

    while (!q.empty())
    {
        pair<int, int> front = q.front();
        q.pop();
        for (auto it : adjList[front.first])
        {
            pair<int, int> temp;
            temp.first = it.first;
            temp.second = it.second + front.second;
            if (dist[temp.first] > temp.second)
            {
                q.push(temp);
                dist[temp.first] = it.second + front.second;
            }
        }
    }
    int time = 0;
    for (int i = 1; i <= N; i++)
    {
        if (dist[i] == INT_MAX)
            return -1;
        time = max(time, dist[i]);
    }
    return time;
}

int main()
{
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4;
    int k = 2;

    cout << minSignalTime(times, n, k);

    return 0;
}
// T.C=O(V+E)
// S.C=O(V+E)