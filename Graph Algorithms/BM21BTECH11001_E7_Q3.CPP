#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>> &adj, int V)
{
    vector<int> colour(V, -1);

    queue<pair<int, int>> q;

    for (int i = 0; i < V; i++)
    {

        if (colour[i] == -1)
        {
            q.push({i, 0});
            colour[i] = 0;

            while (!q.empty())
            {
                pair<int, int> p = q.front();
                q.pop();

                int v = p.first;
                int c = p.second;

                for (int j : adj[v])
                {

                    if (colour[j] == c)
                    {
                        return false;
                    }

                    if (colour[j] == -1)
                    {
                        colour[j] = (c) ? 0 : 1;
                        q.push({j, colour[j]});
                    }
                }
            }
        }
    }
    return true;
}

int main()
{

    int V = 4;
    vector<vector<int>> adj = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};

    (isBipartite(adj, V)) ? cout << "true\n" : cout << "false\n";

    return 0;
}
// Time Complexity: O(V+E)
// Auxiliary Space: O(V)