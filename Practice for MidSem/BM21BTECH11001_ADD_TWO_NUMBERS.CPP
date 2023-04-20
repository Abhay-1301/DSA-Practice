#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    unsigned long long sum1 = 0;
    unsigned long long sum2 = 0;
    list<int> list1, list2;
    cin >> n;
    cin >> m;
    int N = n - 1;
    int M = m - 1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        list1.emplace_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        list2.emplace_back(x);
    }
    for (auto it = list1.begin(); it != list1.end(); it++)
    {
        // sum = sum + (*(it)) * (pow(10, N));
        sum1 = sum1 * 10 + (*(it));
        N--;
    }
    for (auto it = list2.begin(); it != list2.end(); it++)
    {
        // sum = sum + (*(it)) * (pow(10, M));
        sum2 = sum2 * 10 + (*(it));
        M--;
    }
    unsigned long long sum = sum1 + sum2;
    list<int> list3;
    string a = to_string(sum);
    for (int i = 0; a[i] != '\0'; i++)
    {
        int x = int(a[i]) - 48;
        list3.emplace_back(x);
    }
    for (auto it = list3.begin(); it != list3.end(); it++)
    {
        cout << *(it) << " ";
    }
    return 0;
}