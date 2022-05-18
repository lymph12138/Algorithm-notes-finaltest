/*
124
class Solution {
public:
    int maxsum=-1010;
    int maxVal(TreeNode* root){
        if(!root)   return 0;
        int lval=maxVal(root->left);
        int rval=maxVal(root->right);
        maxsum=max({root->val+lval+rval,root->val+lval,root->val+rval,root->val,maxsum});
        return max({root->val+lval,root->val+rval,root->val});
    }
    int maxPathSum(TreeNode* root) {
        maxVal(root);
        return maxsum;
    }
};
*/