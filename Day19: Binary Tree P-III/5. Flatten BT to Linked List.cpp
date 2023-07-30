#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *cur = root;
    while(cur != NULL){
        if(cur->left != NULL){
            TreeNode<int> *prev = cur->left;
            while(prev->right){
                prev = prev->right;
            }
            // reached the rightmost node of left subtree
            prev->right = cur->right;
            // making the link
            cur->right = cur->left;
            // reinitialise for next loop, finding the leftmost
        }
        cur = cur->right;
    }
    return root;
}
