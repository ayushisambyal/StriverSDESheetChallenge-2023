int getMaxWidth(TreeNode<int> *root)
{
    if(root==NULL) return 0;
    queue<TreeNode<int> *>q;
    q.push(root);

    int ans=1;
    while(!q.empty()){
        int size= q.size();
        ans=max(size, ans);

        for(int i=0; i<size; i++){
            TreeNode<int> *node= q.front();f
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            q.pop();
        }
    }
    return ans;
}
