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

int kthSmallest(TreeNode<int> *root, int k)
{
	TreeNode<int>* cur=root;
        int cnt=0;
        int res=-1;
        while(cur!=NULL){
            if(cur->left==NULL){
                if(cnt==k-1){
                    res=cur->data;
                }
                cnt++;
                cur=cur->right;
            }
            else{
                TreeNode<int>* prev=cur->left;
                while(prev->right!=NULL && prev->right!=cur)
                    prev=prev->right;
                
                if(prev->right==NULL){
                    prev->right=cur;
                    cur=cur->left;
                }
                else{
                    if(cnt==k-1) res=cur->data;
                    cnt++;
                    prev->right=NULL;
                    cur=cur->right;
                }
            }   
        }
        return res;
}
