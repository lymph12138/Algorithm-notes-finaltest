/*
1373
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
struct Node
{
    int l,r,sum,tag;
};

class Solution {
public:
    int ans=0;
    Node BST(TreeNode* root)
    {
        if(!root->left && !root->right)
        {
            ans=max(ans,root->val);
            return (Node){root->val,root->val,root->val,1};
        }
        int sum=root->val;bool valid=true;
        int l=root->val,r=root->val;
        if(root->left)
        {
            Node L=BST(root->left);
            if(L.tag && root->val>L.r)
            {
                sum+=L.sum;
                l=L.l;
            }
            else    valid=false;
        }
        if(root->right)
        {
            Node R=BST(root->right);
            if(R.tag && root->val<R.l)
            {
                sum+=R.sum;
                r=R.r;
            }
            else    valid=false;
        }
        if(valid)
        {
            ans=max(ans,sum);
            return (Node){l,r,sum,1};
        }
        return  (Node){0,0,0,0};
    }
    int maxSumBST(TreeNode* root) 
    {
        if(!root)   return 0;
        BST(root);
        return ans;
    }
};