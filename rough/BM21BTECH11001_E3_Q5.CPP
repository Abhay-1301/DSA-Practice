#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

int main()
{
    Node *root = NULL;
    // 45 21 34 65 89 12 97 2 6 1 65 22 11 77 44 22 99 -1

    inputToInsert(root);

    levelOrderTraversal(root);
    cout << endl;

    inOrder(root);
    cout << endl;

    int i = 0;
    int j = 0;

    int k = 3;

    cout << Kth_smallest(root, i, k) << endl;

    cout << Kth_largest(root, j, k) << endl;

    cout << LCAinBST(root, 34, 89) << endl;

    return 0;
}