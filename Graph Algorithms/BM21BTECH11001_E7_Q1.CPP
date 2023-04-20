#include <bits/stdc++.h>
using namespace std;

int shortestLen(string sWord, string eWord, set<string> &dict)
{
    int currentLength = 0;
    int wordLen = sWord.size();
    queue<string> q;
    q.push(sWord);
    while (!q.empty())
    {
        currentLength++;
        int currQlen = q.size();
        for (int i = 0; i < currQlen; i++)
        {
            string frontWord = q.front();
            q.pop();
            for (int i = 0; i < wordLen; i++)
            {
                char sChar = frontWord[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    frontWord[i] = c;
                    if (frontWord == eWord)
                    {
                        return currentLength + 1;
                    }
                    if (dict.find(frontWord) == dict.end())
                    {
                        continue;
                    }
                    dict.erase(frontWord);
                    q.push(frontWord);
                }
                frontWord[i] = sChar;
            }
        }
    }
    return 0;
}

int main()
{
    set<string> dict;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");
    dict.insert("cog");
    string sWord = "hit";
    string eWord = "cog";
    cout << shortestLen(sWord, eWord, dict);
    return 0;
}
// T.C = O(N^2*M) , N = dict.size()
// S.C = O(N*M)  ,  M = word.size()