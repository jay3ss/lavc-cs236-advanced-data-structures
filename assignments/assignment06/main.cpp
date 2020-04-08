#include <iostream>
#include "AVLTree.h"

using namespace std;

int main()
{
    AVLTreeType<int> treeRoot;
    int num;

    cout << "Enter numbers ending with -999" << endl;
    cin >> num;
    while (num != -999)
    {
        treeRoot.insert(num);
        cin >> num;
    }

    cout << endl << "Tree nodes in inorder: ";
    treeRoot.inorderTraversal();

    cout << endl;
    cout << endl << "Tree nodes in preorder: ";
    treeRoot.preorderTraversal();
    cout << endl;

    return 0;
}
