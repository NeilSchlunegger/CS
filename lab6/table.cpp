#include "table.h"

void duplicate(node* root, node*& newRoot)
{
	if(root == NULL)
	{
		newRoot = NULL;
		return;
	}

	newRoot = new node;
	newRoot->data = root->data;
	duplicate(root->left, newRoot->left);
	duplicate(root->right, newRoot->right);
}

void remove(node*& root, int target)
{
	return remHelper(root, target);
}

void remHelper(node*& root, int target)
{
	if(!root)
	{
		std::cout << "Not found";
		return;
	}
	if(root->data == target)
	{
		delNode(root);
		return;
	}
	else if(root->data < target)
	{
		return remHelper(root->right, target);
	}
	else
	{
		return remHelper(root->left, target); // go left if root->data is bigger
	}
}

void delNode(node*& root)
{
	node* temp;

	//case 1: leaf
	if(!root->right && !root->left)
	{
		delete root;
		root = NULL;
	}
	//case 2a: no right
	else if(!root->right)
	{
		temp = root;
		root = root->left;
		temp->left = NULL; 
		delete temp;
	}
//	case 2b: no left
	else if(!root->left)
	{
		temp = root;
		root = root->right;
		temp->right = NULL;
		delete temp;
	}
//	case 3: no children
	else
	{
		node* curr = root->right; // find in order successor with this
		node* prev = NULL;

		while(curr->left)
		{
			prev = curr;
			curr = curr->left;
		}

		root->data = curr->data; // exchange items to preserve BST
		
		if(!prev)
		{
			root->right = curr->right;//disconnect curr
		}
		else
		{
			prev->left = curr->right; // in case in-order successor has a right child
		}

		curr->right = NULL;
		delete curr;
	}
}
