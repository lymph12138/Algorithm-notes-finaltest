/*
213
*/
class Solution {
public:
    int rob2(vector<int>& nums,int i, int j){
        int n=j-i+1;
        if(n==1)    return nums[i];
        if(n==2)    return max(nums[i],nums[j]);
        vector<int> dp(n,0);
        int ans=0;
        dp[0]=nums[i];
        dp[1]=max(nums[i],nums[i+1]);
        dp[2]=max(nums[i]+nums[i+2],nums[i+1]);
        for(int l=i+3;l<=j;l++)
            dp[l-i]=max(dp[l-i-2]+nums[l],dp[l-i-3]+nums[l]);
        return max(dp[n-1],dp[n-2]);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)    return nums[0];
        int max1=rob2(nums,0,n-2);
        int max2=rob2(nums,1,n-1);
        return max(max1,max2);
    }
};