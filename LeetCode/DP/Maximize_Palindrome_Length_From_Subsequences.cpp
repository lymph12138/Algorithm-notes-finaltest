/*
1771
*/
class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        string word=word1+word2;
        vector<vector<int>> dp(n+m,vector<int>(n+m,0));
        for(int i=0;i<n+m;i++)  dp[i][i]=1;
        int ans=0;
        for(int len=2;len<=n+m;len++){
            for(int i=0;i+len-1<n+m;i++){
                int j=len+i-1;
                if(word[i]==word[j]){
                    dp[i][j]=dp[i+1][j-1]+2;
                    if(i<n && j>=n) ans=max(ans,dp[i][j]);
                }
                else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return ans;
    }
};