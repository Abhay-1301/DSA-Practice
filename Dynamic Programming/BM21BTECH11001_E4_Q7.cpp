#include <bits/stdc++.h>
using namespace std;

void NthPascal(int N)
{
    if (N < 0)
    {
        cout << "Not a valid input.";
        return;
    }
    // nC0 = 1
    unsigned long long prev = 1;
    cout << prev << "  ";

    for (int i = 1; i <= N; i++)
    {
        // nCr = (nCr-1 * (n - r + 1))/r
        unsigned long long curr = ((prev * (N - i + 1)) % 1000000007) / i;
        cout << curr << "  ";
        prev = curr;
    }
}

int main()
{
    int n;
    cout << "Enter the row number: ";
    cin >> n;
    NthPascal(n);
    return 0;
}

// T.C = O(N)
// S.C = O(1)