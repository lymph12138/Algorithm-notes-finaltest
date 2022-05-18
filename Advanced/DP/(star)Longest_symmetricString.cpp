/*

*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
#define maxn 1010
int main(){
    int ans=1;
    string s;
    getline(cin,s);
    int len=s.length();
    int dp[maxn][maxn];
    fill(dp[0],dp[0]+maxn*maxn,0);
    for(int i=0;i<len;i++){
        dp[i][i]=1;
        if(i<len-1){
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                ans=2;
            }
        }
    }
    for(int L=3;L<=len;L++){
        for(int i=0;i+L-1<len;i++){
            int j=i+L-1;
            if(s[i]==s[j] && dp[i+1][j-1]==1){
                dp[i][j]=1;
                ans=L;
            }
        }
    }
    cout<<ans;

    return 0;
}