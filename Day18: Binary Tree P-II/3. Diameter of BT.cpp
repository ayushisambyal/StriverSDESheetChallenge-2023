int helper(TreeNode<int> *node, int &dia){
    if(!node) return 0;
    int lh = helper(node->left, dia);
    int rh = helper(node->right, dia);
    dia = max(dia, lh+rh);
    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	int dia = 0;
    // find the height of left & right child separately
    helper(root, dia);
    return dia;
}
