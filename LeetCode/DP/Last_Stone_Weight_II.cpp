/*
1049
*/
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        if(n==1)    return stones[0];
        if(n==2)    return abs(stones[0]-stones[1]);
        int sum=0;
        for(auto s:stones)  sum+=s;
        int target=sum/2;
        sort(stones.begin(),stones.end());
        if(stones.back()>target)    return 2*stones.back()-sum;
        vector<int> dp(target+1,0);
        for(int i=0;i<n;i++){
            for(int j=target;j>=stones[i];j--){
                dp[j]=max(dp[j],dp[j-stones[i]]+stones[i]);
            }
        }
        return sum-2*dp[target];
    }
};