bool identicalTrees(BinaryTreeNode<int>* p, BinaryTreeNode<int>* q) {
    if(p==NULL || q==NULL) return p==q;

    return(p->data == q->data)
        && identicalTrees(p->left, q->left)
        && identicalTrees(p->right, q->right);
}
