#include "BST.h"

BST::BST() 
	: data(0)
	, left(nullptr)
	, right(nullptr)
{
}

BST::BST(int value)
{
	data = value;
	left = nullptr;
	right = nullptr;
}

BST::~BST()
{
}

BST* BST::insert(BST* root, int value)
{
	// If root is null then insert a new node.
	if (root == nullptr)
	{
		return new BST(value);
	}

	// If the value is greater than the root then it gets insereted to the right. Left if lesser than.
	if (value > root->data)
	{
		root->right = insert(root->right, value);
	}
	else if (value < root->data)
	{
		root->left = insert(root->left, value);
	}

	return root;
}

BST* BST::search(BST* root, int value)
{
	// Root is null or the value is found at the root.
	if (root == nullptr || root->data == value)
		return root;

	// Value is greater than root->data
	if (root->data < value)
		return search(root->right, value);

	// Value is smaller than root->data
	return search(root->left, value);
}

BST* BST::deleteNode(BST* root, int value)
{
	// Tree is empty or value was not found
	if (root == nullptr)
		return root;

	if (root->data > value)
	{
		root->left = deleteNode(root->left, value);
		return root;
	}
	else if (root->data < value)
	{
		root->right = deleteNode(root->right, value);
		return root;
	}

	// One child is empty
	if (root->left == nullptr)
	{
		BST* temp = root->right;
		delete root;
		return temp;
	}
	else if (root->right == nullptr)
	{
		BST* temp = root->left;
		delete root;
		return temp;
	}
	else // Both children exist
	{
		BST* succParent = root;

		BST* succ = root->right;
		while (succ->left != nullptr)
		{
			succParent = succ;
			succ = succ->left;
		}

		if (succParent != root)
			succParent->left = succ->right;
		else
			succParent->right = succ->right;

		root->data = succ->data;

		delete succ;
		return root;
	}
	

}

void BST::storeNodes(BST* root, vector<BST*>& nodes)
{
	if (root == nullptr)
		return;

	storeNodes(root->left, nodes);
	nodes.push_back(root);
	storeNodes(root->right, nodes);
}

BST* BST::buildTree(vector<BST*>& nodes, int start, int end)
{
	if (start > end)
		return nullptr;

	int mid = (start + end) / 2;
	BST* root = nodes[mid];

	root->left = buildTree(nodes, start, mid - 1);
	root->right = buildTree(nodes, mid + 1, end);

	return root;
}

BST* BST::balanceTree(BST* root)
{
	vector<BST*> nodes;
	storeNodes(root, nodes);

	int n = nodes.size();
	return buildTree(nodes, 0, n - 1);
}

void BST::inorder(BST* root)
{
	if (root == nullptr)
		return;

	inorder(root->left);
	cout << root->data << ", ";
	inorder(root->right);
}

void BST::preorder(BST* root)
{
	if (root == nullptr)
		return;

	cout << root->data << ", ";

	preorder(root->left);
	preorder(root->right);
}

void BST::postorder(BST* root)
{
	if (root == nullptr)
		return;

	postorder(root->left);
	postorder(root->right);

	cout << root->data << ", ";
}
