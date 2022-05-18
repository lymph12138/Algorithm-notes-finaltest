/*
139
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(int j=0;j<wordDict.size();j++){
                int k=wordDict[j].size();
                if(i<k)    continue;
                dp[i]=(wordDict[j]==s.substr(i-k,k) && dp[i-k]) || dp[i];
            }
        }
        return dp[n];
    }
};