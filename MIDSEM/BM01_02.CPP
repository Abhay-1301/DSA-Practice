#include <bits/stdc++.h>
using namespace std;
int main()
{
   long long int n;
    cin >> n;
    long long int arr[n];
    arr[0] = 1;
    arr[1] = 1;
    for (long long int i = 2; i < n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    reverse(arr, arr + n);
    for (long long int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

// TC = O(n)
// SC = O(n)