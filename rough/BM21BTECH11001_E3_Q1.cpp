#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

int main()
{
    Node *root = NULL;

    root = createBinaryTree(root);

    // 0 1 3 -1 -1 5 -1 -1 2 4 -1 -1 6 -1 -1 (Copy paste this to make tree)
    levelOrderTraversal(root);

    cout << "Diameter is " << DiameterAndHeight(root).first << endl;
    cout << "Height is " << DiameterAndHeight(root).second << endl;

    return 0;
}