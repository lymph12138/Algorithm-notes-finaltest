/*
1145
*/

class Solution {
public:
    int leftsum=0;
    int rightsum=0;
    int dfs(TreeNode* root, int x){
        if(!root)   return 0;
        int left=dfs(root->left, x);
        int right=dfs(root->right,x);
        if(root->val==x){
            leftsum=left;
            rightsum=right;
        }
        return left+right+1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int sum=dfs(root,x);
        if(leftsum>sum/2 || rightsum>sum/2 || (sum-leftsum-rightsum-1)>sum/2)
            return true;
        return false;
    }
};