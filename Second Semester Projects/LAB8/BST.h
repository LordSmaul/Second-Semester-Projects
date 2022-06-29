#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

class BST
{
private:
	struct treeNode
	{
		int value;
		treeNode *left;
		treeNode *right;
	};
	treeNode *root;

	void copy(treeNode *&, treeNode *);
	void insert(treeNode *&, treeNode *);
	void displayInOrder(treeNode *) const;
	void destroySubTree(treeNode *);

public:
	BST();				  // BST default constructor
	BST(const BST &tree); // BST copy constructor
	~BST();				  // BST destructor

	void insertNode(int); // Inserts a node
	void display();		  // Displays the tree in ascending order
};

BST::BST() // BST default constructor
{
	root = NULL;
}

BST::BST(const BST &tree) // BST copy contructor
{
	root = NULL;
	copy(root, tree.root);
}

BST::~BST() // BST destructor
{
	destroySubTree(root);
}

void BST::insertNode(int value) // Inserts node into the BST
{
	treeNode *newNode = new treeNode;
	newNode->value = value;
	newNode->left = newNode->right = NULL;

	insert(root, newNode);
}

void BST::display() // Displays BST in order
{
	displayInOrder(root);
}

void BST::copy(treeNode *&node, treeNode *treeCopy) // Copies BST to another BST
{
	if (treeCopy)
	{
		// Creates new node
		treeNode *newNode = new treeNode;
		newNode->value = treeCopy->value;
		newNode->left = newNode->right = NULL;

		// Inserts new node, then copies it through the tree
		insert(node, newNode);
		copy(node, treeCopy->left);
		copy(node, treeCopy->right);
	}
}

void BST::insert(treeNode *&node, treeNode *newNode) // Recursive insert function
{
	if (node == NULL)
	{
		node = newNode;
	}
	else if (newNode->value < node->value)
	{
		insert(node->left, newNode);
	}
	else
	{
		insert(node->right, newNode);
	}
}

void BST::displayInOrder(treeNode *node) const // Recursive display function
{
	if (node)
	{
		displayInOrder(node->left);
		cout << node->value << " ";
		displayInOrder(node->right);
	}
}

void BST::destroySubTree(treeNode *node) // Recursive destructive function
{
	if (node)
	{
		if (node->left)
		{
			destroySubTree(node->left);
		}
		if (node->right)
		{
			destroySubTree(node->right);
		}
		delete node;
	}
}

#endif