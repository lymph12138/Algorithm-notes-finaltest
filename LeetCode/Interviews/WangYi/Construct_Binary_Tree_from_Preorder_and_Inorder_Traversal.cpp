/*
105
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
    int index;
    int findIndex(vector<int>& inorder, int val, int l, int r){
        for(int i=l;i<=r;i++)
            if(inorder[i]==val)
                return i;
        return -1;
    }
    TreeNode* buildPreorder(vector<int>& preorder, vector<int>& inorder, int l, int r){
        if(r<l) return nullptr;
        TreeNode* node=new TreeNode(preorder[index++]);
        int pos=findIndex(inorder, node->val, l, r);
        node->left=buildPreorder(preorder, inorder, l, pos-1);
        node->right=buildPreorder(preorder, inorder, pos+1, r);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        index=0;
        return buildPreorder(preorder, inorder, 0, inorder.size()-1);
    }
};