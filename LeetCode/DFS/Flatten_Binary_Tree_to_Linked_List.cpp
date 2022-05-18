/*
114
class Solution {
public:
    vector<TreeNode*> num;
    void DFS(TreeNode* root){
        if(!root)   return ;
        num.push_back(root);
        DFS(root->left);
        DFS(root->right);
    }
    void flatten(TreeNode* root) {
        DFS(root);
        if(!root)    return ;
        TreeNode* temp=root;
        for(int i=1;i<num.size();i++){
            temp->right=num[i];
            temp->left=nullptr;
            temp=temp->right;
        }
    }
};
*/