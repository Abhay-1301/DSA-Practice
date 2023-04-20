#include <bits/stdc++.h>
using namespace std;

int LPS(string str)
{
    int maxlen = 0;
    int first;
    int len = str.length();
    int dp[len][len] = {0};

    // for palindromes of length 1
    for (int i = 0; i < len; i++)
    {
        dp[i][i] = 1;
        maxlen = 1;
    }
    
    // for palindromes of length 2
    for (int i = 0; i < len - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            dp[i][i + 1] = 1;
            first = i;
            maxlen = 2;
        }
    }

    // for palindromes of length 3 and more
    for (int i = 3; i <= len; i++)
    {
        for (int j = 0; j < len - i + 1; j++)
        {
            int mid = dp[j + 1][j + i - 2];
            if (str[j] == str[j + i - 1] && mid == 1)
            {
                dp[j][j + i - 1] = 1;
                maxlen = i;
                first = j;
            }
        }
    }
    // string ans = str.substr(first, maxlen);
    return maxlen;
}

int main()
{
    string str;
    cout << "Enter the string:" << endl;
    cin >> str;
    cout << LPS(str) << endl;
    return 0;
}

// n = string.length()
// T.C = O(n*n)
// S.C = O(n*n)