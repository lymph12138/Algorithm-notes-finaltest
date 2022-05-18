/*
474
*/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(auto s:strs){
            int zeros=count(s.begin(),s.end(),'0');
            int ones=s.size()-zeros;
            for(int j=m;j>=zeros;j--){
                for(int l=n;l>=ones;l--){
                    dp[j][l]=max(dp[j][l],dp[j-zeros][l-ones]+1);
                }
            }
        }
        return dp[m][n];
    }
};