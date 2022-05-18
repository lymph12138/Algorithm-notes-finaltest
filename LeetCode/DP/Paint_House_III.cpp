/*
1473
*/
class Solution {
private:
    vector<vector<vector<int>>> dp;

    int maxcost=1e6+5;
public:
    int dfs(vector<int>& houses,vector<vector<int>>& cost,int idx,int temp,int precolor){
        if(idx>=houses.size() || temp<0)    return temp==0?temp:maxcost;
        if(houses[idx]!=0)  return dfs(houses,cost,idx+1,temp-(houses[idx]!=precolor),houses[idx]);
        if(dp[idx][temp][precolor]) return dp[idx][temp][precolor];
        int res=maxcost;
        for(int color=1;color<=cost[0].size();color++){
            res=min(res,cost[idx][color-1]+dfs(houses,cost,idx+1,temp-(houses[idx]!=precolor),color));
        }
        dp[idx][temp][precolor]=res;
        return res;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        dp.resize(m+5,vector<vector<int>>(m+5,vector<int>(n+5,0)));
        int res=dfs(houses,cost,0,target,0);
        return res>=maxcost?-1:res;
    }
};