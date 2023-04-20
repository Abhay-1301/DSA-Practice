#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    int ke = 0;
    int ko = 0;
    int arr[n];
    stack<int> sto;
    stack<int> ste;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            ste.push(arr[i]);
            ke++;
            if (ke == k+1)
            {
                break;
            }
        }
    }
    reverse(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 != 0)
        {
            sto.push(arr[i]);
            ko++;
            if (ko == k+1)
            {
                break;
            }
        }
    }
    
    cout << sto.top() + ste.top();
    return 0;
}

// TC = O(n)
// SC = O(n)