/*
940
*/
class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.size(),mod=1e9+7;
        vector<int> dp(n+1,0);
        dp[0]=1;
        vector<int> alpha(26,-1);
        for(int j=1;j<=n;j++){
            dp[j]=(2*dp[j-1])%mod;
            if(alpha[s[j-1]-'a']!=-1){
                dp[j]=(dp[j]-dp[alpha[s[j-1]-'a']-1])%mod;
            }
            alpha[s[j-1]-'a']=j;
        }
        while(dp[n]<0)  dp[n]=dp[n]+mod;
        return dp[n]-1;
    }
};