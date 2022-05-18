/*
264
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n,0);
        dp[0]=1;
        int a=0,b=0,c=0,i=1;
        while(i<n){
            dp[i]=min(dp[a]*2,min(dp[b]*3,dp[c]*5));
            if(dp[i]==dp[a]*2)  a++;
            if(dp[i]==dp[b]*3) b++;
            if(dp[i]==dp[c]*5) c++;
            i++;
        }
        return dp[n-1];
    }
};