#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    if (root == NULL)
        return make_pair(-1, -1);

    BinaryTreeNode<int>* suc = NULL;
    BinaryTreeNode<int>* pre = NULL;

    while (root != NULL) {
        if (key > root->data) {
            pre = root;
            root = root->right;
        } 
        else if (key < root->data) {
            suc = root;
            root = root->left;
        } 
        else {
            if (root->left != NULL) {
                pre = root->left;
                while (pre->right != NULL)
                    pre = pre->right;
            }
            if (root->right != NULL) {
                suc = root->right;
                while (suc->left != NULL)
                    suc = suc->left;
            }
            break;
        }
    }

    int predVal = (pre != NULL) ? pre->data : -1;
    int succVal = (suc != NULL) ? suc->data : -1;

    return make_pair(predVal, succVal);
}
