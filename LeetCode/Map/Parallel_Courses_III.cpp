/*
2050
*/
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> next[n+1],dp(n+1,0);
        set<int> before[n+1];
        queue<int> q;
        for(auto r:relations){
            next[r[0]].push_back(r[1]);
            before[r[1]].insert(r[0]);
        }
        for(int i=1;i<=n;i++){
            next[0].push_back(i);
            before[i].insert(0);
        }
        dp[0]=0;q.push(0);int ans=0;
        while(!q.empty()){
            int u=q.front();q.pop();
            for(auto v:next[u]){
                dp[v]=max(dp[v],dp[u]+time[v-1]);
                before[v].erase(u);
                if(before[v].size()==0) q.push(v);
            }
            ans=max(ans,dp[u]);
        }
        return ans;
    }
};

class Solution {
public:
    int dfs(int x, vector<vector<int>>& edges, vector<int>& time, vector<int>& dp){
        if(dp[x])   return dp[x];
        int ans=0;
        for(int i=0;i<edges[x].size();i++)
            ans=max(ans,dfs(edges[x][i],edges,time,dp));
        dp[x]=ans+time[x-1];
        return dp[x];
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> dp(n+1,0);
        vector<vector<int>> edges(n+1);
        for(int i=0;i<relations.size();i++)
            edges[relations[i][1]].push_back(relations[i][0]);
        int ans=0;
        for(int i=1;i<=n;i++)
            ans=max(ans,dfs(i,edges,time,dp));
        return ans;
    }
};