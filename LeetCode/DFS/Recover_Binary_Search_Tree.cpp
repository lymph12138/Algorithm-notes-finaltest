/*
99
class Solution {
public:
    vector<int> num;
    int count=0;
    void DFS(TreeNode* root,int tag){
        if(!root)   return ;
        DFS(root->left,tag);
        if(tag==1)  num.push_back(root->val);
        else    root->val=num[count++];
        DFS(root->right,tag);
    }
    void recoverTree(TreeNode* root) {
        DFS(root,1);
        sort(num.begin(),num.end());
        DFS(root,2);
    }
};
*/