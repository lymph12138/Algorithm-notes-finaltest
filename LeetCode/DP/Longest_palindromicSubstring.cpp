/*
5
class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        int dp[len][len];
        int ans=1;int start=0;
        for(int i=0;i<len;i++)
            for(int j=0;j<len;j++)
                    dp[i][j]=0;
        for(int i=0;i<len;i++){
            dp[i][i]=1;
            if(i<len-1 && s[i]==s[i+1]){
                ans=2;
                start=i;
                dp[i][i+1]=1;
            }
        }
        for(int L=3;L<=len;L++){
            for(int i=0;i+L-1<len;i++){
                int j=i+L-1;
                if(s[i]==s[j] && dp[i+1][j-1]==1){
                    ans=L;
                    dp[i][j]=1;
                    start=i;
                }
            }
        }
        return s.substr(start,ans);
    }
};
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define maxn 1010
int dp[maxn][maxn];

int main(){
    string s;
    cin>>s;
    int len=s.length();
    fill(dp[0],dp[0]+maxn*maxn,0);
    int ans=1;int start=0;
    for(int i=0;i<len;i++){
        dp[i][i]=1;
        if(i<len-1 && s[i]==s[i+1]){
            dp[i][i+1]=1;
            ans=2;
            start=i;
        }
    }
    for(int L=3;L<=len;L++){
        for(int i=0;i+L-1<len;i++){
            int j=i+L-1;
            if(s[i]==s[j] && dp[i+1][j-1]==1){
                dp[i][j]=1;
                ans=L;
                start=i;
            }
        }
    }
    for(int i=start;i<start+ans;i++)
        printf("%c",s[i]);
    
    return 0;
}