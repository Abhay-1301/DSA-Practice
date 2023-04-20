#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
    return;
}

void maxHeapify(vector<int> &arr, int i)
{
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < arr.size() && arr[max] < arr[left])
    {
        max = left;
    }
    if (right < arr.size() && arr[max] < arr[right])
    {
        max = right;
    }
    if (max != i)
    {
        swap(arr[max], arr[i]);
        maxHeapify(arr, max);
    }
}

void maxHeapHeapify(vector<int> &arr)
{
    for (int i = arr.size() / 2; i >= 0; i--)
    {
        maxHeapify(arr, i);
    }
    return;
}

void minHeapify(vector<int> &arr, int i)
{
    int min = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < arr.size() && arr[min] < arr[left])
    {
        min = left;
    }
    if (right < arr.size() && arr[min] < arr[right])
    {
        min = right;
    }
    if (min != i)
    {
        swap(arr[min], arr[i]);
        minHeapify(arr, min);
    }
}
void minHeapHeapify(vector<int> &arr)
{
    for (int i = arr.size() / 2; i >= 0; i--)
    {
        minHeapify(arr, i);
    }
    return;
}
class maxHeap
{
public:
    vector<int> arr;
    maxHeap()
    {
        arr.push_back(0);
    }

    void insert(int val)
    {
        arr[0]++;
        int index = arr[0];
        arr.push_back(val);
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void deleteRoot()
    {
        if (arr[0] == 0)
        {
            return;
        }
        arr[1] = arr[arr[0]];
        arr[0]--;

        int i = 1;
        while (i < arr[0])
        {
            int left = 2 * i;
            int right = 2 * i + 1;

            if (left < arr[0] && arr[i] < arr[left])
            {
                swap(arr[i], arr[left]);
                i = left;
            }
            else if (right < arr[0] && arr[i] < arr[right])
            {
                swap(arr[i], arr[right]);
                i = right;
            }
            else
            {
                return;
            }
        }
    }

    int maxElement()
    {
        return arr[1];
    }

    int minElement()
    {
        return *min_element(arr.begin() + arr.size() / 2 + 1, arr.end());
    }

    void print()
    {
        for (int i = 1; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class minHeap
{
public:
    vector<int> arr;
    minHeap()
    {
        arr.push_back(0);
    }

    void insert(int val)
    {
        arr[0]++;
        int index = arr[0];
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] > arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void deleteRoot()
    {
        if (arr[0] == 0)
        {
            return;
        }
        arr[1] = arr[arr[0]];
        arr[0]--;

        int i = 1;
        while (i < arr[0])
        {
            int left = 2 * i;
            int right = 2 * i + 1;

            if (left < arr[0] && arr[i] > arr[left])
            {
                swap(arr[i], arr[left]);
                i = left;
            }
            else if (right < arr[0] && arr[i] > arr[right])
            {
                swap(arr[i], arr[right]);
                i = right;
            }
            else
            {
                return;
            }
        }
    }

    int minElement()
    {
        return arr[1];
    }

    int maxElement()
    {
        return *max_element(arr.begin() + arr.size() / 2 + 1, arr.end());
    }

    void print()
    {
        for (int i = 1; i < arr[0]; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    maxHeap h;
    h.insert(54);
    h.insert(53);
    h.insert(55);
    h.insert(52);
    h.insert(50);
    h.print();
    vector<int> arr = {54, 53, 55, 52, 50};
    maxHeapHeapify(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

// Insert : TC = O(log n) , S.C = O(1)
// delete : TC = O(log n) , S.C = O(1)
// heapify : TC = O(n) , S.C = O(1)