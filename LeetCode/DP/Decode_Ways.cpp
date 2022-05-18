/*
91
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
class Solution {
public:
    bool figure(string s){
        if(s[0]=='0')   return false;
        else if(stoi(s)>26) return false;
        else    return true;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,0);
        dp[0]=figure(s.substr(0,1))?1:0;
        if(n==1 || s[0]=='0')    return dp[0];
        dp[1]=(figure(s.substr(1,1))?dp[0]:0)+(figure(s.substr(0,2))?1:0);
        for(int i=2;i<n;i++){
            dp[i]=(figure(s.substr(i,1))?dp[i-1]:0)+(figure(s.substr(i-1,2))?dp[i-2]:0);
        }
        return dp[n-1];
    }
};
int main(){
    string s="123";
    cout<<Solution().numDecodings(s);

    return 0;
}