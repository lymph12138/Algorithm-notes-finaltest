/*
10
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++)
            for(int j=0;j<=n;j++)
                dp[i][j]=false;
        dp[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j-1] == '*')
                    dp[i][j]=(i && dp[i-1][j] && (p[j-2]=='.' || s[i-1]==p[j-2])) || dp[i][j-2];
                else
                    dp[i][j]=i && dp[i-1][j-1] && (p[j-1]=='.' || s[i-1]==p[j-1]);
            }
        }
        return dp[m][n];
    }
};
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define maxs 25
#define maxp 35
int dp[maxs][maxp];
int main(){
    string s,p;
    cin>>s>>p;
    fill(dp[0],dp[0]+maxs*maxp,false);
    dp[0][0]=true;
    int m=s.size();int n=p.size();
    for(int i=0;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(p[j-1]!='*')
                dp[i][j]=i && dp[i-1][j-1] && (p[j-1]=='.' || s[i-1]==p[j-1]);

            else
                dp[i][j]=(i && dp[i-1][j] && (p[j-2]=='.' || s[i-1]==p[j-2])) || dp[i][j-2];
        }
    }   
    cout<<dp[m][n];

    return 0;
}