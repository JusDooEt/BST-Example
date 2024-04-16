#pragma once

#include <iostream>
using namespace std;

class BST
{
private:
	int data;
	BST* left;
	BST* right;

public:
	BST();
	BST(int value);
	~BST();

	// Manipulating BST
	BST* insert(BST* root, int value);
	BST* search(BST* root, int value);
	BST* deleteNode(BST* root, int value);

	// Traversing BST
	void inorder(BST* root);
	void preorder(BST* root);
	void postorder(BST* root);
};

