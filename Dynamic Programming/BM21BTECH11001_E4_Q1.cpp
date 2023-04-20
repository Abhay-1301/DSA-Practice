#include <bits/stdc++.h>
using namespace std;

int totalWays(vector<int> coins, int amount)
{
    int dp[amount + 1] = {0};

    // Base case
    dp[0] = 1;

    for (int i = 0; i < coins.size(); i++)
    {
        for (int j = coins[i]; j <= amount; j++)
        {
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[amount];
}

int main()
{
    int k;
    cout << "Enter the amount you want to make:" << endl;
    cin >> k;
    int n;
    cout << "Enter the number of elements in the array:" << endl;
    cin >> n;
    vector<int> coin;
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        coin.push_back(x);
    }
    cout << totalWays(coin, k);
    return 0;
}

// T.C = O(N*amount)
// S.C = O(amount)