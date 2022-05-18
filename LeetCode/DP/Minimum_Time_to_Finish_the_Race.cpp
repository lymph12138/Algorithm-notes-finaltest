/*
2188
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        vector<int> dp(numLaps,INT_MAX);
        int mx=0;
        for(int i=0;i<tires.size();i++){
            int cur=0,p=0;
            while(cur<changeTime && p<numLaps){
                cur+=tires[i][0]*pow(tires[i][1],p);
                dp[p]=min(dp[p],cur+changeTime);
                p++;
            }
            mx=max(mx,p);
        }
        for(int i=1;i<numLaps;i++)
            for(int j=0;j<min(mx,i);j++)
                dp[i]=min(dp[i],dp[j]+dp[i-j-1]);
        return dp[numLaps-1]-changeTime;
    }
};

int main(){
    vector<vector<int>> tires;
    int t,n;
    cout<<Solution().minimumFinishTime(tires,t,n);

    return 0;
}