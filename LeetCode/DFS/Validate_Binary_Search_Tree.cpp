/*
98
class Solution {
public:
    int count=0;
    int num[10010];
    void DFS(TreeNode* node){
        if(node->left!=NULL)    DFS(node->left);
        if(node!=NULL)  num[count++]=node->val;
        if(node->right!=NULL)   DFS(node->right);
    }
    bool isValidBST(TreeNode* root) {
        DFS(root);
        for(int i=1;i<count;i++)
            if(num[i]<=num[i-1])
                return false;
        return true;
    }
};
*/