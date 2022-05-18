/*
1508
*/

class Solution {
private:
    int mo=1e9+7;
    vector<int> ans;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int dp[n][n];
        for(int i=0;i<n;i++){
            dp[i][i]=nums[i];
            ans.push_back(dp[i][i]%mo);
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                if(i==0)    dp[i][j]=dp[i+1][j]+nums[i];
                else    dp[i][j]=dp[i][j-1]+nums[j];
                ans.push_back(dp[i][j]%mo);
            }
        }
        sort(ans.begin(),ans.end());
        int res=0;
        for(int i=left-1;i<right;i++)
            res=(res+ans[i])%mo;
        return res;
    }
};