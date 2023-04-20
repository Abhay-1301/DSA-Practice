#include <bits/stdc++.h>
using namespace std;

int smallestPositiveMissingNumber(vector<int> &arr)
{

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 1)
        {
            arr[i] = arr.size() + 2;
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (abs(arr[i]) < arr.size())
        {
            if (arr[abs(arr[i])] > 0)
            {
                arr[abs(arr[i])] = (arr[abs(arr[i])]) * (-1);
            }
        }
    }

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > 0)
        {
            return i;
        }
        if (i == arr.size() - 1)
        {
            return arr.size();
        }
    }
}

int main()
{
    vector<int> arr = {7,8,9,11,12};
    cout << smallestPositiveMissingNumber(arr);
    return 0;
}

// Time Complexity: O(N). 
// Space Complexity: O(1)