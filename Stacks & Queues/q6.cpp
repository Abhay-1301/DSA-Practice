#include <iostream>
#include <stack>
#include <string>

using namespace std;

string output(string word)
{
    string value;
    stack<char> st;
    char val = word[0];
    for (int i = 1; word[i] != '\0'; i++)
    {
        if (word[i] == val)
        {
            continue;
        }
        else if ((word[i] != val) && i == 0)
        {
            st.push(word[i]);
        }
        else if (word[i] != st.top())
        {
            st.push(word[i]);
        }
        else if (word[i] == st.top())
        {
            val = st.top();
            st.pop();
        }
    }
for(int i = 0;st.empty()==true;i++){
 value[i]=st.top();
    st.pop();
}
    return value;
}

int main()
{
    string word;
    cin >> word;
    cout<< output(word) <<endl;
    return 0;
}