#include <bits/stdc++.h>
using namespace std;

bool isSafeToGoUp(int i)
{
    if (i == 0)
    {
        return false;
    }
    return true;
}
bool isSafeToGoLeft(int j)
{
    if (j == 0)
    {
        return false;
    }
    return true;
}
bool isSafeToGoDown(int i, int m)
{
    if (i == m - 1)
    {
        return false;
    }
    return true;
}
bool isSafeToGoRight(int j, int n)
{
    if (j == n - 1)
    {
        return false;
    }
    return true;
}

void ratRace(vector<vector<int>> &arr, int i, int j, int m, int n, vector<string> &ans, string &tempAns)
{
    // cout<<tempAns<<" ";
    if (i == m - 1 && j == n - 1)
    {
        ans.push_back(tempAns);
        // cout << ans << endl;
        return;
    }
    if (isSafeToGoDown(i, m) && arr[i + 1][j] != 0)
    {
        tempAns.push_back('D');
        ratRace(arr, i + 1, j, m, n, ans, tempAns); // D
        tempAns.pop_back();
    }
    if (isSafeToGoRight(j, n) && arr[i][j + 1] != 0)
    {
        tempAns.push_back('R');
        ratRace(arr, i, j + 1, m, n, ans, tempAns); // R
        tempAns.pop_back();
    }

    // if (isSafeToGoLeft(j) && arr[i][j - 1] != 0)
    // {
    //     tempAns.push_back('L');
    //     ratRace(arr, i, j - 1, m, n, ans, tempAns); // L
    //     tempAns.pop_back();

    // }
    // if (isSafeToGoUp(i) && arr[i - 1][j] != 0)
    // {
    //     tempAns.push_back('U');
    //     ratRace(arr, i - 1, j, m, n, ans, tempAns); // U
    //     tempAns.pop_back();

    // }
}

int main()
{
    vector<string> ans;
    string tempAns;
    int m, n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    ratRace(arr, 0, 0, m, n, ans, tempAns);
    for (auto it = ans.begin(); it != ans.end(); it++)
    {
        cout << *(it) << " ";
    }
    return 0;
}

// Time Complexity: O(2^(n^2)). 
// Space Complexity: O(n^2)