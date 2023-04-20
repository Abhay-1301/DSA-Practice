#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &str, int i, int j)
{
    while (i < j)
    {
        if (str[i] == str[j])
        {
            i++;
            j--;
        }
        else
            return false;
    }
    return true;
}

void partition(string &str, int i, vector<string> &temp_ans, vector<vector<string>> &ans)
{
    if (i == str.length())
    {
        ans.emplace_back(temp_ans);
        return;
    }

    for (int x = i; x < str.length(); x++)
    {
        if (isPalindrome(str, i, x))
        {
            temp_ans.emplace_back(str.substr(i, x - i + 1));
            partition(str, x + 1, temp_ans, ans);
            temp_ans.pop_back();
        }
    }
}

int main()
{
    string str;
    vector<string> temp_ans;
    vector<vector<string>> ans;
    cout << "Enter your string: " << endl;
    cin >> str;
    partition(str,0,temp_ans,ans);
    for (auto it : ans)
    {
        for (auto ptr : it)
        {
            cout << ptr << " ";
        }
        cout << endl;
    }
    return 0;
}

// Time Complexity: O(n. 2^n)
// Auxiliary Space: O(n) -> recursion stack space