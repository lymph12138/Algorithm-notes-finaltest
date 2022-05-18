/*
279
*/
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,n);
        for(int i=1;i*i<=n;i++)
            dp[i*i]=1;
        for(int i=2;i<=n;i++){
            int min=n;
            if(dp[i]>1){
                for(int j=1;j*j<i;j++){
                    if(dp[i-j*j]<min)   min=dp[i-j*j];
                    if(min==1)  break;
                }
                dp[i]=min+1;
            }
        }
        return dp[n];
    }
};
