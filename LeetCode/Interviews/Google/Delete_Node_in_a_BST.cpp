/*
450
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
    TreeNode* delte(TreeNode* root, int key){
        if(root->val==key){
            if(!root->left) return root->right;
            if(!root->right)    return root->left;
            TreeNode* temp=root->right;
            while(temp->left)  temp=temp->left;
            temp->left=root->left;
            return root->right;
        }
        if(root->val>key && root->left)    root->left=delte(root->left,key);
        else if(root->val<key && root->right)   root->right=delte(root->right,key);
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)   return root;
        root=delte(root, key);
        return root;
    }
};