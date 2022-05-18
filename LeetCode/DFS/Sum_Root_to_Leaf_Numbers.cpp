/*
129
class Solution {
public:
    int ans=0;
    void PreOrder(TreeNode* root,string t){
        if(!root)   return;
        if(!root->left && !root->right){
            t+='0'+root->val;
            ans+=stoi(t);
            return;
        }
        PreOrder(root->left,t+char('0'+root->val));
        PreOrder(root->right,t+char('0'+root->val));
    }
    int sumNumbers(TreeNode* root) {
        PreOrder(root,"");
        return ans;
    }
};
*/