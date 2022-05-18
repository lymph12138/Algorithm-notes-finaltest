/*
115
*/
#include <cstdio>
#include <iostream>
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        int m=s.size();int n=t.size();
        double dp[m+1][n+1];
        for(int i=0;i<=m;i++)   dp[i][0]=1;
        for(int j=1;j<=n;j++)   dp[0][j]=0;
        for(int j=1;j<=n;j++)
            for(int i=1;i<=m;i++)
                dp[i][j]=dp[i-1][j]+(s[i-1]==t[j-1]?dp[i-1][j-1]:0);
        return dp[m][n];
    }
};

int main(){
    string s="abcc";
    string t="abc";
    cout<<Solution().numDistinct(s,t);

    return 0;
}