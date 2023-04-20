#include <bits/stdc++.h>
using namespace std;

void subsets(vector<int> &set, vector<vector<int>> &ans, vector<int> &subset, int index)
{
    for (int i = index; i < set.size(); i++)
    {
        subset.push_back(set[i]);
        ans.push_back(subset);
        subsets(set, ans, subset, i + 1);
        subset.pop_back();
    }
}

int main()
{
    vector<int> set = {3, 4, 5};
    vector<int> subset;
    vector<vector<int>> ans;

    subsets(set, ans, subset, 0);

    for (vector<int> it : ans)
    {
        for (int ptr : it)
        {
            cout << ptr << " ";
        }
        cout << endl;
    }
    return 0;
}

// Time Complexity: O(n. 2^n)
// Auxiliary Space: O(n) -> recursion stack space