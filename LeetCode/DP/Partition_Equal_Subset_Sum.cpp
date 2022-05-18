/*
416
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(auto num:nums)  sum+=num;
        if(sum%2)   return false;
        vector<int> dp(sum/2+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            if(nums[i]>sum/2)   return false;
            for(int j=sum/2;j>=nums[i];j--)
                dp[j]=(dp[j] || dp[j-nums[i]]);
            dp[nums[i]]=1;
        }
        return dp.back();
    }
};