int dfsh(BinaryTreeNode<int> *root){
    if(root == NULL) return 0;
    
    int lh = dfsh(root->left);
    if(lh == -1) return -1;
    int rh = dfsh(root->right);
    if(rh == -1) return -1;

    if(abs(lh - rh) > 1) return -1;
    return max(lh, rh) + 1;
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    return dfsh(root) != -1;
}
