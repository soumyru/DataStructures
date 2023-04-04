#include<iostream>
#include "BinaryTreeNode.cpp"
using namespace std;

void printTree(BinaryTreeNode<int> * root)
{
    if(root==NULL)
    return;

    cout<<root->data<<":";
    if(root->left!=NULL)
    cout<<"L"<<root->left->data;

    if(root->right!=NULL)
    cout<<"R"<<root->right->data;

    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

/*Input format:
1
2
-1 (left of 2)
-1(right of 2)
3
-1(left of 3)
-1(right of 3)

           1
          / \
         2   3
*/
BinaryTreeNode<int>* takeInput()
{
    int rootData;
    cout<<"Enter data"<<endl;
    cin>>rootData;
    if(rootData==-1)
    return NULL;

    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild=takeInput();
    BinaryTreeNode<int>* rightChild=takeInput();
    root->left=leftChild;
    root->right=rightChild;
    return root;
}

int main()
{
    BinaryTreeNode<int>* root=takeInput();
    printTree(root);
}