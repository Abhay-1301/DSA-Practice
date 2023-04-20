#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(vector<vector<int>> &flights, int n, int src, int dst, int K)
{
    vector<vector<pair<int, int>>> edges(n);
    for (auto it : flights)
    {
        edges[it[0]].emplace_back(it[1], it[2]);
    }

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<int> current;
    int currentCost, currentSrc, currentK;

    pq.push({0, src, K + 1});

    while (!pq.empty())
    {
        current = pq.top();
        pq.pop();
        currentCost = current[0];
        currentSrc = current[1];
        currentK = current[2];
        if (currentSrc == dst)
        {
            return currentCost;
        }
        if (currentK > 0)
        {
            for (auto it : edges[currentSrc])
            {
                pq.push({currentCost + it.second, it.first, currentK - 1});
            }
        }
    }

    return -1;
}

int main()
{
    int n = 4;
    int src = 0;
    int dst = 3;
    int k = 1;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    cout << findCheapestPrice(flights, n, src, dst, k);
    return 0;
}
// T.C = O(nlogN)
// S.C=O(n)