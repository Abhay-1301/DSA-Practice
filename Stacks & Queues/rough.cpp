#include <iostream>
#include <stack>
#include <string>

using namespace std;

// void output(string word)
// {
//     string value;
//     stack<char> st;
//     char val = word[0];
//     for (int i = 1; word[i] != '\0'; i++)
//     {
//         if (word[i] == val)
//         {
//             continue;
//         }
//         else if ((word[i] != val) && i == 0)
//         {
//             st.push(word[i]);
//         }
//         if (word[i] != st.top())
//         {
//             st.push(word[i]);
//         }
//         else if (word[i] == st.top())
//         {
//             val = st.top();
//             st.pop();
//         }
//     }
// while(!st.empty()){
//     cout<<st.top()<<endl;
//     st.pop();
// }

// }

int main()
{
//     string word;
//     cin >> word;
//     string value;
//     stack<char> st;
//     char val = word[0];
//     for (int i = 1; word[i] != '\0'; i++)
//     {
//         if (word[i] == val)
//         {
//             continue;
//         }
//         else if ((word[i] != val) && i == 0)
//         {
//             st.push(word[i]);
//         }
//         if (word[i] != st.top())
//         {
//             st.push(word[i]);
//         }
//         else if (word[i] == st.top())
//         {
//             val = st.top();
//             st.pop();
//         }
//     }
//     while (!st.empty())
//     {
//         cout << st.top() << endl;
//         st.pop();
//     }

    stack <int> st;
    cout<<st.top()<<endl;
    return 0;
}