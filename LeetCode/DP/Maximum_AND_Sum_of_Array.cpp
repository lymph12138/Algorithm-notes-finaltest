/*
2172
*/
class Solution {
public:
    int dp(int i,int ns,int mask,vector<int>& memo,vector<int>& nums){
        if(memo[mask]>0)    return memo[mask];
        if(i<0) return 0;
        for(int slot=1,bit=1;slot<=ns;slot++,bit*=3)
            if((mask/bit)%3>0)
                memo[mask]=max(memo[mask],(nums[i]&slot)+dp(i-1,ns,mask-bit,memo,nums));
        return memo[mask];
    }
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int mask=pow(3,numSlots)-1;
        vector<int> memo(mask+1,0);
        return dp(nums.size()-1,numSlots,mask,memo,nums);
    }
};