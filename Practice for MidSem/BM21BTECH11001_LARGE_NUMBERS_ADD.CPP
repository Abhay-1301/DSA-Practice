#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    list<int> list1, list2, list3;
    cin >> n;
    cin >> m;
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

    // for (auto it1 = list1.rbegin(); it1 != list1.rend(); it1--)

    auto it1 = list1.rbegin();
    auto it2 = list2.rbegin();
    int carry = 0;
    while (it1 != list1.rend() && it2 != list2.rend())
    {
        int sum = *(it1) + *(it2) + carry;
        if (sum >= 10)
        {
            list3.push_front(sum - 10);
            carry = 1;
        }
        else
        {
            list3.push_front(sum);
            carry = 0;
        }
        it1++;
        it2++;
    }
    if (it2 == list2.rend())
    {
        while (it1 != list1.rend())
        {
            int sum = *(it1) + carry;
            if (sum >= 10)
            {
                list3.push_front(sum - 10);
                carry = 1;
            }
            else
            {
                list3.push_front(sum);
                carry = 0;
            }
            it1++;
        }
    }
    if (it1 == list1.rend())
    {
        while (it2 != list2.rend())
        {
            int sum = *(it2) + carry;
            if (sum >= 10)
            {
                list3.push_front(sum - 10);
                carry = 1;
            }
            else
            {
                list3.push_front(sum);
                carry = 0;
            }
            it2++;
        }
    }
    if (carry == 1)
    {
        list3.push_front(1);
    }

    for (auto it3 = list3.begin(); it3 != list3.end(); it3++)
    {
        cout << *(it3) << " ";
    }
    return 0;
}