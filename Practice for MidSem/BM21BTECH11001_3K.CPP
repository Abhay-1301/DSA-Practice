#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    int count = 0;
    cin >> n;
    cin >> k;
    stack<int> st;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 3 == 0)
        {
            st.push(arr[i]);
            count++;
        }
        if (count == k)
        {
            cout << st.top();
            break;
        }
    }

    return 0;
}