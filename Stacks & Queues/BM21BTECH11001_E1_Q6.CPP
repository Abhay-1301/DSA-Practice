#include <bits/stdc++.h>
using namespace std;
int main()
{
    int counter = 0;
    cout << "Enter the String: ";
    string word;
    cin >> word;
    stack<char> s;
    for (int i = 0; i < word.length(); i++)
    {
        if (!s.empty())
        {
            if (word[i] != s.top())
            {
                if (counter != 1)
                {
                    for (int j = 0; j < counter; j++)
                        s.pop();
                }
                if (!s.empty() && word[i] == s.top())
                    counter = 1;
                else
                    counter = 0;
            }
        }
        counter++;
        s.push(word[i]);
        if (i == word.length() - 1 && counter != 1)
        {
            for (int j = 0; j < counter; j++)
                s.pop();
        }
    }
    stack<char> temp;
    while (!s.empty())
    {
        temp.push(s.top());
        s.pop();
    }
    while (!temp.empty())
    {
        cout << temp.top();
        temp.pop();
    }
    return 0;
}



// Time Complexity: O(n)
// Space Complexity: O(n)
