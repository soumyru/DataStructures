#include<iostream>
using namespace std;
template<typename T>
class BinaryTreeNode
{
    public:
    T data;
    BinaryTreeNode * left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data)
    {
        this->data=data;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};