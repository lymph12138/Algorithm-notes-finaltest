/*
799
*/
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(100,vector<double>(100,0));
        dp[0][0]=poured;
        int i,j;
        for(i=0;i<99;i++){
            for(j=0;j<=i;j++){
                if(dp[i][j]>1){
                    dp[i+1][j]+=(dp[i][j]-1)/2.0;
                    dp[i+1][j+1]+=(dp[i][j]-1)/2.0;
                }
            }
            if(i>query_row && j>query_glass)  break;
        }
        return min(1.0,dp[query_row][query_glass]);
    }
};