/*
337
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
    map<TreeNode*,int> mp;
    int rob(TreeNode* root) {
        if(!root)   return 0;
        if(mp.count(root))  return mp[root];
        int nowsum=root->val,childsum=0;
        if(root->left)
            nowsum=nowsum+rob(root->left->left)+rob(root->left->right);
        if(root->right)
            nowsum=nowsum+rob(root->right->left)+rob(root->right->right);
        childsum=childsum+rob(root->left)+rob(root->right);
        mp[root]=max(nowsum,childsum);
        return mp[root];
    }
};