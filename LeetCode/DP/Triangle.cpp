/*
120
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int dp[m+1][m+1];
        int ans=200*10000+10;
        dp[0][1]=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=i;j++){
                if(j==1)    dp[i][j]=triangle[i-1][j-1]+dp[i-1][j];
                else if(i==j)   dp[i][j]=triangle[i-1][j-1]+dp[i-1][j-1];
                else  dp[i][j]=triangle[i-1][j-1]+min(dp[i-1][j-1],dp[i-1][j]);  
                if(i==m)    ans=min(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
int main(){
    int num[3][4]={};
    cout<<Solution().minimumTotal(num);

    return 0;
}