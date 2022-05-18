/*
44
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int i=0;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j-1]=='*')
                    dp[i][j]=(i && dp[i-1][j]) || dp[i][j-1];
                else
                    dp[i][j]=(i && dp[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='?'));
            }
        }
        return dp[n][m];
    }
};