vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if(!root) return ans;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while(!q.empty()){
        for(int i=0; i<q.size(); i++){
            BinaryTreeNode<int> *node = q.front();
            q.pop();

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            ans.push_back(node->val);
        }
    }
    return ans;
}
