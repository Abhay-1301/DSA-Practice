#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter Number of Elements: ";
    int n;
    cin >> n;
    cout << "Enter the Elements\n";
    stack<int> s;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        while (!s.empty() && (arr[i] > arr[s.top()]))
        {
            arr[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty())
    {
        arr[s.top()] = -1;
        s.pop();
    }
    for (int i = 0; i < n - 1; i++)
        cout << arr[i] << ", ";
    cout << arr[n - 1] << "\n";
    return 0;
}


// Time Complexity: O(n^2)
// Space Complexity: O(n)
