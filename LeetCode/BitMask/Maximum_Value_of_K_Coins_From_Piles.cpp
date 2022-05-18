/*
2218
*/
class Solution {
public:
    int dpcaculate(int i, int j,vector<vector<int>>& dp,vector<vector<int>>& piles){
        if(dp[i][j])    return dp[i][j];
        if(i==piles.size())    return 0;
        int ans=dpcaculate(i+1,j,dp,piles),sum=0;
        for(int t=1;t<=j && t<=piles[i].size();t++){
            sum+=piles[i][t-1];
            ans=max(ans, dpcaculate(i+1,j-t,dp,piles)+sum);
        }
        dp[i][j]=ans;
        return ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        
        return dpcaculate(0,k,dp,piles);
    }
};

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        function<int(int,int)> dpcaculate=[&](int i, int j){
            if(dp[i][j])    return dp[i][j];
            if(i==n)    return 0;
            int sum=0,ans=dpcaculate(i+1,j);
            for(int t=1;t<=j&&t<=piles[i].size();t++){
                sum+=piles[i][t-1];
                ans=max(ans,dpcaculate(i+1,j-t)+sum);
            }
            return dp[i][j]=ans;
        };
        
        return dpcaculate(0,k);
    }
};