/*
132
*/
class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        if(n==1 || n==0)    return 0;
        vector<int> dp(n,2010);
        vector<vector<bool>> Pali(n,vector<bool>(n,true));
        for(int len=2;len<=n;len++)
            for(int i=0,j=i+len-1;j<n;i++,j++)
                if(s[i]!=s[j] || !Pali[i+1][j-1])
                    Pali[i][j]=false;
        dp[0]=0;
        for(int i=0;i<n;i++){
            if(Pali[0][i]){
                dp[i]=0;
                continue;
            }
            for(int j=1;j<=i;j++){
                if(Pali[j][i]){
                    dp[i]=min(dp[i],dp[j-1]+1);
                }
            }
        }
        return dp[n-1];
    }
};