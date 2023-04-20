#include <bits/stdc++.h>
using namespace std;

// Implementing stack using queue
// Push time complexity : O(n)
// Pop time complexity : O(1)
// Space Complexity: O(n)

class Stack
{
public:
    queue<int> q;

    void push(int data)
    {
        int s = q.size();

        q.push(data);

        for (int i = 0; i < s; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    void pop()
    {
        if (q.empty())
            cout << "No elements\n";
        else
            q.pop();
    }

    int top()
    {
        return (q.empty()) ? -1 : q.front();
    }
    bool empty()
    {
        return (q.empty());
    }
};

// Implementing queue using stack
// Push time complexity : O(1)
// Pop time complexity : O(n)
// Space Complexity: O(n)

class Queue
{
public:
    stack<int> s;

    void Push(int x)
    {
        s.push(x);
    }

    int Pop()
    {
        if (s.empty())
        {
            cout << "Queue is empty";
            exit(0);
        }

        int x = s.top();
        s.pop();

        if (s.empty())
            return x;

        int item = Pop();

        s.push(x);

        return item;
    }
};

int main()
{
    Stack st;
    st.push(30);
    st.push(60);
    st.push(80);
    st.pop();
    st.pop();
    cout << st.top();

    Queue q;
    q.Push(20);
    q.Push(30);
    q.Pop();
    q.Push(40);
    return 0;
}
