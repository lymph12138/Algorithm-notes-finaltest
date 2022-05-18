/*
1031
*/


class Solution {
public:
    int helper(vector<int>& dp,int f, int s){
        int maxf=dp[f],maxfs=dp[f+s];
        for(int i=f+s+1;i<dp.size();i++){
            int curf=dp[i-s]-dp[i-s-f];
            int curs=dp[i]-dp[i-s];
            maxf=max(maxf,curf);
            maxfs=max(maxfs,maxf+curs);
        }
        return maxfs;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++)    dp[i]=nums[i-1]+dp[i-1];
        return max(helper(dp,firstLen,secondLen),helper(dp,secondLen,firstLen));
    }
};