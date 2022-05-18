/*
113
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void Travel(TreeNode* root,int targetSum,vector<int> temp){
        if(!root)   return ;
        if(root)    temp.push_back(root->val);
        if(root && !root->left && !root->right){
            int sum=0;
            for(int i=0;i<temp.size();i++)
                sum+=temp[i];
            if(sum==targetSum)  ans.push_back(temp);
        }
        if(root->left)
            Travel(root->left,targetSum,temp);
        if(root->right)
            Travel(root->right,targetSum,temp);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        Travel(root,targetSum,temp);
        return ans;
    }
};
*/