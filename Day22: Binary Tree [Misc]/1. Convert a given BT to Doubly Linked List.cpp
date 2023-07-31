#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

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
    };

*************************************************************/

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>* prev = NULL;
    BinaryTreeNode<int>* head = NULL;

    function<void(BinaryTreeNode<int>*)> inorderTraversal = [&](BinaryTreeNode<int>* root) {
        if (!root) return;

        inorderTraversal(root->left);

        if (!prev) {
            // This is the first node of DLL, so update the head
            head = root;
        } else {
            // Rewire the pointers to create the DLL
            prev->right = root;
            root->left = prev;
        }

        // Update prev to the current node for the next iteration
        prev = root;

        inorderTraversal(root->right);
    };

    inorderTraversal(root);

    return head;
}
