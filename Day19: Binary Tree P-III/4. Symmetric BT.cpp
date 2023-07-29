/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
bool helper(BinaryTreeNode<int> *l, BinaryTreeNode<int> *r){
    if(l==NULL || r==NULL) return l==r;
    if(l->data != r->data) return false;
    return helper(l->left, r->right) && helper(l->right, r->left);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    return root == NULL || helper(root->left, root->right); 
}
