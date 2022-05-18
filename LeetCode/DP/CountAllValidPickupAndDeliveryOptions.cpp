/*
1359
class Solution {
public:
    int m=1e9+7;
    int countOrders(int n) {
        vector<long long int> dp(n+1,0);
        dp[1]=1;
        for(int i=2;i<=n;i++)
            dp[i]=(dp[i-1]%m)*(2*i-1)*i;
        return dp[n]%m;
    }
};
*/
