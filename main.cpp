#include "BST.h"


int main()
{
    //====== Variables =============================================

    BST b;
    BST *root = NULL;

    //==============================================================
    
    //====== Inserting Nodes in a BST ==============================

    root = b.insert(root, 10);
    b.insert(root, 8);
    b.insert(root, 7);
    b.insert(root, 6);
    b.insert(root, 5);
    //b.insert(root, 60);
    //b.insert(root, 80);
    
    //==============================================================
 
    //====== Traversing a BST ======================================

    cout << "Original BST: ";
    b.inorder(root);
    cout << endl << endl;
    cout << "Preorder Traversal: ";
    b.preorder(root);
    cout << endl << endl;
    cout << "PostOrder Traversal: ";
    b.postorder(root);
    cout << endl << endl;

    //==============================================================
    
    //====== Balancing a BST =======================================
    
    cout << "Balancing BST...\n";
    root = b.balanceTree(root);
    cout << "Preorder Traversal: ";
    b.preorder(root);
    cout << endl << endl;

    //==============================================================

    //====== Searching in a BST ====================================

    int key = 6;

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

    //==============================================================

    //====== Deleting Nodes in a BST ===============================

    cout << "\nDelete Node: 7\n";
    root = b.deleteNode(root, 7);
    cout << "Modified BST tree after deleting Node:\n";
    b.inorder(root);

    cout << "\n\nDelete Node: 8\n";
    root = b.deleteNode(root, 8);
    cout << "Modified BST tree after deleting Node:";
    b.inorder(root);

    cout << "\n\nDelete Node: 10\n";
    root = b.deleteNode(root, 10);
    cout << "Modified BST tree after deleting Node:\n";
    b.inorder(root);

    //==============================================================


    return 0;
}