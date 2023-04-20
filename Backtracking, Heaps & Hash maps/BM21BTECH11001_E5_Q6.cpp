#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int> &arr, int K)
{
    priority_queue<int> maxHeap; // By default its max heap

    for (int i = 0; i < K; i++)
    {
        // Push first K elements into heap
        maxHeap.push(arr[i]);
    }

    // Now check from k to last element
    for (int i = K; i < arr.size(); i++)
    {
        if (arr[i] < maxHeap.top())
        {
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }
    return maxHeap.top();
}

int kthLargest(vector<int> &arr, int K)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < K; i++)
    {
        // Push first K elements into heap
        minHeap.push(arr[i]);
    }

    // Now check from k to last element
    for (int i = K; i < arr.size(); i++)
    {
        if (arr[i] > minHeap.top())
        {
            minHeap.pop();
            minHeap.push(arr[i]);
        }
    }
    return minHeap.top();
}

int main()
{
    vector<int> arr = {1, 7, 2, 3, 4, 5, 6, 7, 0, 13, 3};

    int K = 2;

    cout << kthSmallest(arr, K) << " and " << kthLargest(arr, K);
}

// Time complexity: O(N * log K)
// Auxiliary Space: O(K)