#include <bits/stdc++.h>
using namespace std;
int balanced(string s)
{
    int n = s.length();
    stack<char> st;
    stack<char> st2;
    stack<char> st3;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ')' && st.empty())
        {
            return 0;
        }
        if (s[i] == ')' && st.top() =='*')
        {
            st.push(s[i]);
        }
        if (s[i] == ')' && st.top() ==')')
        {
            st.push(s[i]); 
        }
        if (s[i] == ')' && st.top() =='(')
        {
            st.pop();
        }

        if ((s[i] == '(' && st.empty()) || (s[i] == '(' && st.top() == '*'))
        {
            st.push(s[i]);
        }
        if (s[i] == '(' && st.top() =='(')
        {
            st.push(s[i]);
        }
        if (s[i] == '(' && st.top() ==')')
        {
            st.push(s[i]);
        }


        if (s[i] == '*' && st.empty())
        {
            st.push(s[i]);
        }
        if (s[i] == '*' && st.top() == '(')
        {
            st.push(s[i]);
        }
        if (s[i] == '*' && st.top() == ')')
        {
            st.push(s[i]);
        }
        if (s[i] == '*' && st.top() == '*')
        {
            st.push(s[i]);
        }
    }

    if(st.empty()){
        return 1;
    }
    while(!st.empty()){
       if(st.top()=='*'){
        st.pop();
       }
       else{
        st2.push(st.top());
        st.pop();
       }
    }
    while(!st2.empty()){
        if(st2.top()='('){
            st3.push(st2.top());
            st2.pop();
        }
    }
    
    return 0;
}
int main()
{
    string s;
    cin>>s;
    cout << balanced(s);
    return 0;
}

// TC = O(n)
// SC = O(n)