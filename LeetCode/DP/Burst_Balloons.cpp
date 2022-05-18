/*
312
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int l=3;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;
                for(int k=i+1;k<j;k++)
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j]);
            }
        }
        return dp[0][n-1];
    }
};

int main(){
    vector<int> nums={1,2,5,8};
    cout<<Solution().maxCoins(nums);

    return 0;
}