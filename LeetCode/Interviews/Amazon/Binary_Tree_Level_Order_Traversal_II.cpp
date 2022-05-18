/*
107
*/
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans,temp;
        if(!root)   return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int size=q.size();
            vector<int> level;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
                level.push_back(node->val);
                q.pop();
            }
            temp.push_back(level);
        }
        for(int i=temp.size()-1;i>=0;i--)
            ans.push_back(temp[i]);
        return ans;
    }
};