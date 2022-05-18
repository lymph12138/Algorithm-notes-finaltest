/*
862
*/
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        long n=nums.size(),ans=n+1;
        vector<long> dp(n,0);
        dp[0]=nums[0];
        deque<long> pos;
        for(long i=0;i<n;i++){
            if(i>0) dp[i]=dp[i-1]+nums[i];
            if(dp[i]>=k)  ans=min(ans,i+1);
            while(pos.size() && dp[i]-dp[pos.front()]>=k){
                ans=min(ans,i-pos.front());
                pos.pop_front();
            }
            while(pos.size() && dp[i]<=dp[pos.back()])
                pos.pop_back();
            pos.push_back(i);
        }
        return ans<=n?ans:-1;
    }
};