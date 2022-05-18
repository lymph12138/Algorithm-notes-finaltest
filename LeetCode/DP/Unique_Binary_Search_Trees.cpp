/*
96
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        if(n==1)    return 1;
        if(n==2)    return 2;
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            for(int j=0;j<i;j++){
                dp[i]+=dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};
int main(){
    int n=4;
    cout<<Solution().numTrees(n);

    return 0;
}