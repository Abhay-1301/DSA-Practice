#include <bits/stdc++.h>
using namespace std;

int balanced(string brackets)
{
    stack<char> st;
    for (int i = 0; brackets[i] != '\0'; i++)
    {
        if ((brackets[i] == ')' || brackets[i] == '}' || brackets[i] == ']') && st.empty())
        {
            return 0;
        }
        if (brackets[i] == '(' || brackets[i] == '{' || brackets[i] == '[')
        {
            st.push(brackets[i]);
        }

        else if ((brackets[i] == ')' && st.top() == '(') || (brackets[i] == '}' && st.top() == '{') || (brackets[i] == ']' && st.top() == '['))
        {
            st.pop();
        }

        else
        {
            return 0;
        }
    }
    if (st.empty())
    {
        return 1;
    }
    else
        return 0;
}

int main()
{
    string brackets;
    cout << "Enter your Brackets Expression : ";
    cin >> brackets;
    if (balanced(brackets))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}


// Time Complexity: O(n)
// Space Complexity: O(n)




// ANOTHER METHOD
//  #include <bits/stdc++.h>
//  using namespace std;
//  int balanced(char expression[])
//  {
//      int l, t = 0;
//      for (l = 0; expression[l] != '\0'; l++)
//          ;
//      char arr[l];
//      for (int i = 0; i < l; i++)
//      {
//          if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
//          {
//              arr[t] = expression[i];
//              t++;
//          }
//          else if (i == 0 || t == 0)
//              return 0;
//          else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
//          {
//              if (expression[i] == ')' && arr[t - 1] == '(')
//                  t--;
//              else if (expression[i] == '}' && arr[t - 1] == '{')
//                  t--;
//              else if (expression[i] == ']' && arr[t - 1] == '[')
//                  t--;
//              else
//                  return 0;
//          }
//      }
//      return 1;
//  }

// int main()
// {
//     char expression[10000];
//     cin >> expression;
//     int z;
//     z = balanced(expression);
//     if (z == 1)
//     {
//         cout << "true" << endl;
//     }
//     else if (z == 0)
//     {
//         cout << "false" << endl;
//     }
//     return 0;
// }