#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    vector<int> arr;
    int frontInd = -1;
    int backInd = -1;

    bool empty()
    {
        if (frontInd == backInd)
            return true;
        else
            return false;
    }

    void push(int val)
    {
        backInd++;
        arr.push_back(val);
    }

    void emplace(int val)
    {
        backInd++;
        arr.push_back(val);
    }

    void pop()
    {
        if (empty())
            cout << "Queue Empty!";
        else
            frontInd++;
        // return arr[frontInd];
    }

    int front()
    {
        frontInd++;
        int i = arr[frontInd];
        frontInd--;
        return i;
    }

    int size()
    {
        int i = backInd-frontInd;
        return i;
    }
};

int main()
{
    Queue q;
    q.push(20);
    q.emplace(30);
    q.pop();
    q.push(40);
    cout << q.front()<<endl;
    cout << q.size()<<endl;
    q.pop();
    return 0;
}

// 
// Time Complexity:
// empty: O(1)
// size(): O(1)
// front(): O(1)
// emplace(): O(1)
// pop(): O(1)
// push(): O(1)

// Space Complexity: O(n)
// 