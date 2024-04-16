#pragma once

#include <iostream>
#include <vector>
using namespace std;

class BST
{
private:
	int data;
	BST* left;
	BST* right;

	// Balancing BST helper functions
	void storeNodes(BST* root, vector<BST*>& nodes);
	BST* buildTree(vector<BST*>& nodes, int start, int end);

public:
	BST();
	BST(int value);
	~BST();

	// Manipulating BST
	BST* insert(BST* root, int value);
	BST* search(BST* root, int value);
	BST* deleteNode(BST* root, int value);

	// Balancing BST
	BST* balanceTree(BST* root);

	// Traversing BST
	void inorder(BST* root);
	void preorder(BST* root);
	void postorder(BST* root);
};

