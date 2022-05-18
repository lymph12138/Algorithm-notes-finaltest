/*
494
*/
class Solution {
public:
    int ans=0;
    void dfs(vector<int>& nums, int target, int pos, int temp){
        if(pos==nums.size() && temp==target)
            ans++;
        if(pos>=nums.size())    return;
        dfs(nums,target,pos+1,temp-nums[pos]);
        dfs(nums,target,pos+1,temp+nums[pos]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0,n=nums.size();
        for(auto num:nums)  sum+=num;
        if(sum+target<0 || target-sum>0)    return 0;
        dfs(nums,target,0,0);
        return ans;
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0,n=nums.size();
        for(auto num:nums)  sum+=num;
        if(sum+target<0 || target-sum>0)    return 0;
        vector<vector<int>> dp(n,vector<int>(sum*2+1,0));
        if(nums[0]==0)  dp[0][sum]=2;
        else{
            dp[0][sum-nums[0]]=1;
            dp[0][sum+nums[0]]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=2*sum;j>=0;j--){
                if(dp[i-1][j]>0){
                    dp[i][j+nums[i]]=dp[i][j+nums[i]]+dp[i-1][j];
                    dp[i][j-nums[i]]=dp[i][j-nums[i]]+dp[i-1][j];
                }
            }
        }
        return dp[n-1][target+sum];
    }
};