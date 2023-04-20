#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Taking Input
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

    // for 1st row (0th bases indexing)
    for (int i = 1; i < n; i++)
    {
        dp[0][i] = dp[0][i - 1] + dp[0][i];
    }

    // for 1st column (0th bases indexing)
    for (int i = 1; i < m; i++)
    {
        dp[i][0] = dp[i - 1][0] + dp[i][0];
    }

    // rest rows and columns
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[m - 1][n - 1] << endl;
    return 0;
}

// T.C = O(n*m)
// S.C = O(n*m)