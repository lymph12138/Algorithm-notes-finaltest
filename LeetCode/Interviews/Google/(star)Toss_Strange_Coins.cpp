/*
1230
*/
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n=prob.size();
        vector<vector<double>> dp(n+1,vector<double>(target+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=target;j++){
                dp[i][j]=dp[i-1][j]*(1-prob[i-1]);
                if(j)   dp[i][j]+=dp[i-1][j-1]*prob[i-1];
            }
        }
        return dp[n][target];
    }
};