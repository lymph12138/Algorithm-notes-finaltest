/*
97
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size();int n=s2.size();int l=s3.size();
        if(m+n!=l)  return false;
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i<m && s3[i+j]==s1[i])
                    dp[i+1][j]=dp[i+1][j]||dp[i][j];
                if(j<n && s3[i+j]==s2[j])
                    dp[i][j+1]=dp[i][j+1]||dp[i][j];
            }
        }
        return dp[m][n];
    }
};
int main(){
    string s1="abc";string s2="ab";string s3="aabbc";
    cout<<Solution().isInterleave(s1,s2,s3);

    return 0;
}