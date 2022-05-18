/*
368
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size(),max=1,id=0;
        sort(nums.begin(),nums.end());
        vector<pair<int,int>> dp(n,{1,-1});
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j].first+1>dp[i].first){
                    dp[i].first=dp[j].first+1;
                    dp[i].second=j;
                }
            }
            if(dp[i].first>max){
                max=dp[i].first;
                id=i;
            }
        }
        vector<int> ans;
        do{
            ans.push_back(nums[id]);
            id=dp[id].second;
        }while(id!=-1);
        return ans;
    }
};