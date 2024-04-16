# BST - Example
## Output
```
Original BST: 5, 6, 7, 8, 10,

Preorder Traversal: 10, 8, 7, 6, 5,

PostOrder Traversal: 5, 6, 7, 8, 10,

Balancing BST...
Preorder Traversal: 7, 5, 6, 8, 10,

searching for 6...
6 found
searching for 60...
60 not found

Delete Node: 7
Modified BST tree after deleting Node:
5, 6, 8, 10,

Delete Node: 8
Modified BST tree after deleting Node:
5, 6, 10,

Delete Node: 10
Modified BST tree after deleting Node:
5, 6,
```
## About
This program is meant to be used as a template for future projects needing a BST (Binary Search Tree) data structure. This program includes a class representing all of the necessary functions for a BST. These functions defined below allow a programmer to use the class methods to manipulate and access the nodes of the BST. The code found in [main.cpp](main.cpp) should be used as an example of how to use the class. The code in main provides examples for inserting, traversing, balancing, searching, and deleting nodes in the BST. This is not a program designed for the general user and should be implemented in the backend of another project.

## BST Class
![image](https://github.com/JusDooEt/BST-Example/assets/152052216/207c1168-4567-429f-afa8-f0fa286b8ddd)

## Manipulators
### insert (root : BST*, value : int) : BST*
- This function will traverse the BST starting at the root and moving to the appropriate child based on the BST parent child relationship. When the function finds a child that is a nullptr, it will create a new node assigned the new value and add it to the BST.
- This function receives the root of the BST and the value to insert into the BST
- This function checks a base case if root == nullptr
  - If true then the function will return a new BST node assigned the passed value.
  - If false then the function will recursively call itself.
    - If the value is greater than the root, the recursive call will be passed the root's right child.
    - If the value is less than the root, the recursive call will be passed the root's left child.
- Returns the root argument.
### deleteNode (root : BST*, value : int) : BST*
- This function will traverse the BST in a similar method as the insert function.
- If a node is found to have an equal value to the one passed to the function, the function will check how many children the matching node has.
  - No Children
    - Node is deleted and assigned to nullptr.
  [![image](https://github.com/JusDooEt/BST-Example/assets/152052216/01860aea-d8e9-4ad2-8f92-0674fbd83d24)](https://www.geeksforgeeks.org/deletion-in-binary-search-tree/)

  - One child
    - The existing child is saved to a temp ptr and is swapped with the matching node.
    - The matching node is deleted and assigned to nullptr.
  [![image](https://github.com/JusDooEt/BST-Example/assets/152052216/8120d1a5-72ad-4124-972f-f067e0371d25)](https://www.geeksforgeeks.org/deletion-in-binary-search-tree/)

  - Two children
    - The function will find the appropriate successor which is the minimum value of the right child of the matching node.
    - The successor and matching node will be swapped.
    - The matching node is deleted and assigned to nullptr.
  [![image](https://github.com/JusDooEt/BST-Example/assets/152052216/db35bff9-3ab0-4589-b397-9d060ec6b55b)](https://www.geeksforgeeks.org/deletion-in-binary-search-tree/)
- Returns the root.
### balanceTree(root : BST*) : BST*
- This function will convert an unbalanced BST into a balanced BST in order to have the most efficient search time complexity of O(h), h representing the height of the BST.
- This function uses two helper functions to balance the tree.
  - storeNodes (root : BST*, nodes : vector<BST*>&) : void
    - This helper function stores the sorted nodes of the BST into a vector
  - buildTree (nodes : vector<BST*>&, start : int, end : int) : BST*
    - This helper function receives the vector initialized in the previous helper function, and two integers representing the start and end.
    - This function will create a mid index using start and end.
    - The root of the BST is assigned to the element of the vector at index mid.
    - The function is called recursively twice, breaking apart the vector around the mid index.
- Returns the root.
```
Input:
       30
      /
     20
    /
   10
Output:
     20
   /   \
 10     30
```
## Accessors
### search (root : BST*, value : int) : BST*
- This function will traverse the BST in a similar method as the insert function.
- If the value passed is equal to a value of a node in the BST, the matching node will be returned.
- If the function traverses to an "empty" node it means the value passed was not found and nullptr is returned.
### inorder (root : BST*) : void
- This function will display all the nodes in the BST in sorted order.
### preorder (root : BST*) : void
- This function will display all the nodes in the BST starting with the root of the tree and descending the left subtree and then the right subtree.
### postorder (root : BST*) : void
- This function will display all the nodes in the BST starting with the bottom of the left subtree, then the right, and finally the root.


[![image](https://github.com/JusDooEt/BST-Example/assets/152052216/22a56fcc-5364-417b-b2a5-20e31b585a26)](https://www.geeksforgeeks.org/binary-search-tree-traversal-inorder-preorder-post-order/)
```
Output: 
Inorder Traversal: 8 12 20 22 25 30 40
Preorder Traversal: 22 12 8 20 30 25 40
Postorder Traversal: 8 20 12 25 40 30 22
```

## Resources
- [https://www.geeksforgeeks.org/convert-normal-bst-balanced-bst/](https://www.geeksforgeeks.org/convert-normal-bst-balanced-bst/)
- [https://www.geeksforgeeks.org/binary-search-tree-traversal-inorder-preorder-post-order/](https://www.geeksforgeeks.org/binary-search-tree-traversal-inorder-preorder-post-order/)
- [https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/](https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/)
- [https://www.geeksforgeeks.org/deletion-in-binary-search-tree/](https://www.geeksforgeeks.org/deletion-in-binary-search-tree/)
- [https://www.geeksforgeeks.org/binary-search-tree-data-structure/](https://www.geeksforgeeks.org/binary-search-tree-data-structure/)


