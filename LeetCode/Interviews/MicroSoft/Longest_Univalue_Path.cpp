/*
687
*/

class Solution {
public:
    int ans=0;
    int dfs(TreeNode* root){
        if(!root)   return 0;
        int l=dfs(root->left);
        int r=dfs(root->right);
        int res1=0,res2=0;
        if(root->left && root->left->val==root->val){
            res1=max(res1,l);
            res2+=l;
        }
        if(root->right && root->right->val==root->val){
            res1=max(res1,r);
            res2+=r;
        }
        ans=max(ans,res2+1);
        return res1+1;  
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root)   return 0;
        dfs(root);
        return ans-1;
    }
};