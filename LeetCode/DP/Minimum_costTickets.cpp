/*
983
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366,0);
        int end=days[days.size()-1];
        int tag=0;
        for(int day=1;day<=end;day++){
            if(day!=days[tag])  dp[day]=dp[day-1];
            else{
                dp[day]=dp[day-1]+costs[0];
                dp[day]=min(dp[max(day-7,0)]+costs[1],dp[day]);
                dp[day]=min(dp[max(day-30,0)]+costs[2],dp[day]);
                tag++;
            }
        }
        return dp[end];
    }
};
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
#define maxn 366
int days[maxn],dp[maxn];
int main(){
    int costs[3],day;
    fill(dp,dp+maxn,0);
    cin>>day;
    for(int i=0;i<day;i++)
        scanf("%d", &days[i]);
    for(int i=0;i<3;i++)
        cin>>costs[i];
    int tag=0;
    int end=days[day-1];
    for(int i=1;i<end;i++){
        if(i!=days[tag])    dp[i]=dp[i-1];
        else{
            dp[i]=dp[i-1]+costs[0];
            dp[i]=min(dp[max(i-7,0)]+costs[1],dp[i]);
            dp[i]=min(dp[max(i-30,0)]+costs[2],dp[i]);
            tag++;
        }
    }
    printf("%d", dp[end]);

    return 0;
}