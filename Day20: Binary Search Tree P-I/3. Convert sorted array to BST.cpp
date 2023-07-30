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
TreeNode<int>* sortedArrToBSTHelper(vector<int> &arr, int start, int end) {
    if (start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    TreeNode<int>* root = new TreeNode<int>(arr[mid]);

    root->left = sortedArrToBSTHelper(arr, start, mid - 1);
    root->right = sortedArrToBSTHelper(arr, mid + 1, end);

    return root;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n) {
    return sortedArrToBSTHelper(arr, 0, n - 1);
}
