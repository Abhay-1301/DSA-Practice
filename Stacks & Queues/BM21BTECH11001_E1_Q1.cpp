
// VECTOR IMPLEMENTATION OF ARRAY
// Here I do not need to define size of stack by myself

#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    vector<int> arr;

    bool empty()
    {
        if (arr.size())
            return false;
        else
            return true;
    }

    void push(int val)
    {
        arr.push_back(val);
    }

    void pop()
    {
        if (empty())
            cout << "Stack Underflow!" << endl;
        else
            arr.pop_back();
    }

    int top()
    {
        if (empty())
        {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        else
            return arr[arr.size() - 1];
    }

    int peek(int i)
    {
        int index = arr.size() - i;
        if (index < 0)
        {
            cout << "Not valid position";
            return -1;
        }
        else
            return arr[index];
    }

    int size()
    {
        return arr.size();
    }
};

int main()
{
    Stack st;
    st.push(30);
    st.push(60);
    cout << st.peek(2) << endl;
    st.pop();
    st.pop();
    st.pop();
    if (st.empty())
        cout << "empty" << endl;
    else
        cout << st.size();
    cout << st.top();
    return 0;
}

// 
// Time Complexity:
// empty: O(1)
// size(): O(1)
// peek(): O(1)
// top(): O(1)
// pop(): O(1)
// push(): O(1)

// Space Complexity: O(n)
// 


// ARRAY IMPLEMENTATION OF STACK.
// Here I have to define size of stack by myself

// #include <bits/stdc++.h>
// using namespace std;

// class Stack
// {
// public:
//     int Size;
//     int Top;
//     int *arr;

//     Stack(int n)
//     {
//         this->Size = n;
//         this->Top = -1;
//         this->arr = new int[Size];
//     }

//     bool empty()
//     {
//         if (Top == -1)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }

//     bool full()
//     {
//         if (Top == Size - 1)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }

//     void push(int val)
//     {
//         if (full())
//         {
//             cout << "Stack Overflow!" << endl;
//         }

//         Top++;
//         arr[Top] = val;
//     }

//     void pop()
//     {
//         if (empty())
//         {
//             cout << "Stack Underflow!" << endl;
//         }
//         else
//         {
//             Top--;
//         }
//     }

//     int top()
//     {
//         if (empty())
//         {
//             cout << "Stack Underflow!" << endl;
//             return -1;
//         }
//         else
//         {
//             return arr[Top];
//         }
//     }

//     int peek(int i)
//     {
//         int index = Top - i + 1;
//         if (index < 0)
//         {
//             cout << "Not valid position" << endl;
//             return -1;
//         }
//         else
//         {
//             return arr[index];
//         }
//     }

//     int size()
//     {
//         return (Top + 1);
//     }
// };

// int main()
// {
//     Stack st(20);
//     st.push(30);
//     st.push(60);
//     cout << st.peek(2) << endl;
//     st.pop();
//     st.pop();
//     st.pop();
//     if (st.empty())
//         cout << "empty" << endl;
//     else
//         cout << st.size();
//     cout << st.top();
//     return 0;
// }
