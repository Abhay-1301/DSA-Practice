#include <bits/stdc++.h>
using namespace std;

int LIS(int arr[], int n)
{
    if (n == 0)
        return 0;

    int temp[n] = {0};

    // points empty slot in temp
    int l = 1;

    temp[0] = arr[0];

    for (int i = 1; i < n; i++)
    {

        // Binary search for the element from begin to begin + length
        int *b = temp;
        int *e = temp + l;
        int *it = lower_bound(b, e, arr[i]);

        // If not present change the temp element to arr[i]
        if (it == temp + l)
        {
            temp[l++] = arr[i];
        }
        else
        {
            *it = temp[i];
        }
    }

    return l;
}

int main()
{
    // taking input
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << LIS(arr, n);

    // below code is O(n^2) approach as discussed in class

    // int dp[n] = {1};

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < i; j++)
    //     {
    //         if (arr[i] > arr[j])
    //         {
    //             dp[i] = max(dp[i], 1 + dp[j]);
    //         }
    //     }
    // }

    // cout << *max_element(dp, dp + n);
    return 0;
}

// T.C = O(nlog(n))
// S.C = O(n)