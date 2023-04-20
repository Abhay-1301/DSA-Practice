#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

int main()
{
    int inOrderArray[] = {5, 8, 10, 3, 14, 20, 22, 25};
    int preOrderArray[] = {20, 8, 5, 3, 10, 14, 22, 25};

    int n = sizeof(inOrderArray) / sizeof(inOrderArray[0]);

    int preOrderIndex = 0;

    Node *root = createBinaryTreeFromPreAndIn(inOrderArray, preOrderArray, preOrderIndex, 0, n - 1, n);

    inOrder(root);
    cout << endl;

    preOrder(root);
    cout << endl;

    postOrder(root);
    cout << endl;
    cout << endl;

    levelOrderTraversal(root);
    cout << endl;

    return 0;
}