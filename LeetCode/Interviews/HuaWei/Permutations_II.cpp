/*
47
*/
class Solution {
public:
    set<string> res;
    void dfs(string temp, vector<bool>& vis,vector<int>& nums){
        if(temp.size()==nums.size()){
            res.insert(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                vis[i]=true;
                char c=nums[i]+10+'a';
                dfs(temp+c,vis,nums);
                vis[i]=false;
            }
        }
    }
    vector<vector<int>> ans;
    void decode(){
        vector<int> temp;
        for(auto it=res.begin();it!=res.end();it++){
            temp.clear();
            for(auto c:*it)
                temp.push_back(c-'a'-10);
            ans.push_back(temp);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<bool> vis(n,false);
        dfs("",vis,nums);
        decode();
        return ans;
    }
};