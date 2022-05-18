/*
1425
*/
class Solution {
    //dp[i]=max((max,dp[j],i-j<=k),0)+nums[i];
    
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size(),ans=nums[0];
        vector<int> dp(n,0);dp[0]=nums[0];
        deque<int> q;q.push_back(0);
        for(int i=1;i<n;i++){
            while(q.size() && i-q.front()>k)
                q.pop_front();
            dp[i]=max(dp[q.front()],0)+nums[i];
            ans=max(ans,dp[i]);
            while(q.size() && dp[i]>=dp[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        return ans;
    }
};