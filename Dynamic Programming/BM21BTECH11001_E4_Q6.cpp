#include <bits/stdc++.h>
using namespace std;
int main()
{
    // taking inputs
    int m, n;
    cin >> m >> n;
    int dp[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dp[i][j];
        }
    }


    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (dp[i][j] != 0)
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
    }

    
    int maximum = -1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
           maximum = max(dp[i][j],maximum);
        }
    }
    cout << maximum*maximum << endl;
    return 0;
}

// T.C = O(n^2)
// S.C = O(n^2)