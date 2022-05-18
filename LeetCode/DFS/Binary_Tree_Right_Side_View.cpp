/*
199
class Solution {
public:
    vector<int> ans;
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root)   return ans;
        q.push(root);
        while(q.size()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* temp;
                temp=q.front();
                if(i==size-1)   ans.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                q.pop();
            }
        }
        return ans;
    }
};
*/