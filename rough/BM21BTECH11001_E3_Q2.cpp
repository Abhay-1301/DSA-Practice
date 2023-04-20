#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

int main()
{
    Node *root = NULL;

    root = createBinaryTree(root);
    // 0 1 3 -1 -1 5 -1 -1 2 4 -1 -1 6 -1 -1 (copy paste this to form tree)

    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    return 0;
}