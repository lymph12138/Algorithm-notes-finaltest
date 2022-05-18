/*
392
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slen=s.size();int tlen=t.size();
        int dp[slen+1][tlen+1];
        for(int i=0;i<=slen;i++) dp[i][0]=0;
        for(int j=0;j<=tlen;j++) dp[0][j]=0;
        for(int i=1;i<=slen;i++){
            for(int j=1;j<=tlen;j++){
                if(s[i-1]==t[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        if(dp[slen][tlen]==slen)    return true;
        else    return false;
    }
};
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define maxs 110
#define maxt 10010
int dp[maxs][maxt];

int main(){
    string s,t;
    cin>>s>>t;
    int slen=s.length();
    int tlen=t.length();
    
    fill(dp[0],dp[0]+maxs*maxt,0);

    for(int i=1;i<=slen;i++){
        for(int j=1;j<=tlen;j++){
            if(s[i-1]==t[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    if(dp[slen][tlen]==slen)
        printf("true");
    else    printf("false");

    return 0;
}