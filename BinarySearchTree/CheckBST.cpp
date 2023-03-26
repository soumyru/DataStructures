#include <iostream>
#include <queue>
using namespace std;
# include <bits/stdc++.h>
#include "BST.cpp"

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int minimum(BinaryTreeNode<int>* root)
{
	if(root==NULL)
	return INT_MAX;

	return (min(root->data,min(minimum(root->left),minimum(root->right))));
}

int maximum(BinaryTreeNode<int>* root)
{
	if(root==NULL)
	return INT_MIN;

	return (max(root->data,max(maximum(root->left),maximum(root->right))));
}


bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
	if(root==NULL)
	return true;
	
	int leftmax=maximum(root->left);
	int rightmax=minimum(root->right);

	bool out=(root->data>leftmax) && (root->data<=rightmax) 
	               && (isBST(root->left)) && (isBST(root->right));

	return out;

}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBST(root) ? "true" : "false");
}