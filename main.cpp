#include "BST.h"


int main()
{
    BST b;
    BST *root = NULL;
    root = b.insert(root, 50);
    b.insert(root, 30);
    b.insert(root, 20);
    b.insert(root, 40);
    b.insert(root, 70);
    b.insert(root, 60);
    //b.insert(root, 80);

    cout << "Original BST: ";
    b.inorder(root);
    cout << endl << endl;
    cout << "Preorder Traversal: ";
    b.preorder(root);
    cout << endl << endl;
    cout << "PostOrder Traversal: ";
    b.postorder(root);
    cout << endl << endl;

    int key = 6;
    // Searching in a BST
    cout << "searching for " << key << "...\n";
    if (b.search(root, key) == NULL)
        cout << key << " not found" << endl;
    else
        cout << key << " found" << endl;

    key = 60;

    cout << "searching for " << key << "...\n";
    if (b.search(root, key) == NULL)
        cout << key << " not found" << endl;
    else
        cout << key << " found" << endl;

    cout << "\nDelete a Leaf Node: 20\n";
    root = b.deleteNode(root, 20);
    cout << "Modified BST tree after deleting Leaf Node:\n";
    b.inorder(root);

    cout << "\n\nDelete Node with single child: 70\n";
    root = b.deleteNode(root, 70);
    cout << "Modified BST tree after deleting single child Node:";
    b.inorder(root);

    cout << "\n\nDelete Node with both child: 50\n";
    root = b.deleteNode(root, 50);
    cout << "Modified BST tree after deleting both child Node:\n";
    b.inorder(root);



    return 0;
}