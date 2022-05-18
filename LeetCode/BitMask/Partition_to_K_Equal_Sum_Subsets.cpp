/*
698
*/
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k==1)    return true;
        int len=nums.size(),sum=0;
        int size=1<<len;
        for(auto num:nums)  sum+=num;
        if(sum%k)   return false;
        sort(nums.begin(),nums.end());
        int target=sum/k;
        if(nums.back()>target)  return false;
        vector<int> cursum(size,0),dp(size,0);
        dp[0]=1;
        for(int i=0;i<size;i++){
            if(!dp[i])  continue;
            for(int j=0;j<len;j++){
                if(i&(1<<j))    continue;
                int next=i|(1<<j);
                if(dp[next])    continue;
                if(cursum[i]%target+nums[j]<=target){
                    cursum[next]=cursum[i]+nums[j];
                    dp[next]=1;
                }
                else    break;
            }
        }
        return dp[size-1];
    }
};