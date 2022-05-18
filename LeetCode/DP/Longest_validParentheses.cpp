/*
32
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size()+1,0);
        int temp,curmax=0;
        for(int i=1;i<=s.size();i++){
            int j=i-2-dp[i-1];
            if(s[i-1]=='(' || j<0 || s[j]==')')
                dp[i]=0;
            else{
                dp[i]=dp[i-1]+2+dp[j];
                curmax=max(dp[i],curmax);
            }
        }
    return curmax;
    }
};
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
#define maxn 30010
int dp[maxn];
int main(){
    string s;
    cin>>s;
    int curmax=0,temp;
    int len=s.length();
    fill(dp,dp+maxn,0);
    for(int i=1;i<=len;i++){
        int j=i-2-dp[i-1];
        if(s[i-1]=='(' || j<0 || s[j]==')')
            dp[i]=0;
        else{
            dp[i]=dp[i-1]+2+dp[j];
            curmax=max(curmax,dp[i]);
        }
    }
    printf("%d", curmax);

    return 0;
}