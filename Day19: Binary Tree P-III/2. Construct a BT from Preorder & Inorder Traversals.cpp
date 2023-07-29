#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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
TreeNode<int> *helper(vector<int> &pre, int ps, int pe, vector<int> in, int is, int ie, map<int, int> &mp){
    if(ps > pe || is > ie) return NULL;

    // initialising the current root
    TreeNode<int> *curroot = new TreeNode<int>(pre[ps]);
    // locate the current root in the inorder traversal
    int indR = mp[curroot->data];
    int numLeft = indR - is; // no. on left - start of current inorder

    curroot->left = helper(pre, ps+1, ps+numLeft, in, is, indR-1, mp);
    curroot->right = helper(pre, ps+numLeft+1, pe, in, indR+1, ie, mp);
    return curroot; 
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	map<int, int> mp;
    // storing indices
    for(int i=0; i<inorder.size(); i++){
        mp[inorder[i]] = i;
    }

    TreeNode<int> *root = helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
    return root;
}
