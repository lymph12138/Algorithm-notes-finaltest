/*
1123
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *ans;
    int solve(TreeNode* root, int d, int &maxd){
        if(!root)   return 0;
        int l=solve(root->left, d+1, maxd);
        int r=solve(root->right, d+1, maxd);
        maxd=max(maxd,d);
        if(l==r && d+l==maxd)   ans=root;
        return max(l,r)+1;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int maxd=0;
        solve(root,0,maxd);
        return ans;
    }
};