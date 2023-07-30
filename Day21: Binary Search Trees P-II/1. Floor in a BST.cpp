#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int x)
{
    int floor = -1;
    while(root){
        if(root->val == x){
            floor = root->val;
            return floor;
        }
        if(x > root->val){
            floor = root->val;
            root = root->right;
        }
        else root = root->left;
    }
    return floor;
}
