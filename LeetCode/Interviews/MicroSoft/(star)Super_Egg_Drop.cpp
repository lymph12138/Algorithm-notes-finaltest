/*
887
*/
class Solution {
public:
    int superEggDrop(int k, int n) {
        if(k==1)    return n;
        if(n==1)    return 1;
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        for(int i=1;i<=k;i++)   dp[1][i]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=k;j++){
                dp[i][j]=1+dp[i-1][j]+dp[i-1][j-1];
                if(dp[i][j]>=n) return i;
            }
        }
        return 0;
    }
};