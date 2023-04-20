#include <bits/stdc++.h>
using namespace std;

int MSS(vector<int> arr)
{
    int max = INT_MIN;
    int maxEnd = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        maxEnd = maxEnd + arr[i];
        if (max < maxEnd)
            max = maxEnd;
        if (maxEnd < 0)
            maxEnd = 0;
    }
    return max;
}

int main()
{
    vector<int> arr;
    cout << "Enter the total number of elements in the array:";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i + 1 << "th "
             << "element: ";
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout << MSS(arr);
    return 0;
}

// T.C = O(N)
// S.C = O(1)