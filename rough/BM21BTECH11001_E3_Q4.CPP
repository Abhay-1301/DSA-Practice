#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

int main()
{
    Node *root = NULL;

    root = createBinaryTree(root);
    // 0 1 3 -1 -1 5 -1 -1 2 4 -1 -1 6 -1 -1

    cout << (LCA(root, 5, 6))->data << endl;

    return 0;
}