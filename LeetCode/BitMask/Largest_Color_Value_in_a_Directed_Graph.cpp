/*
1857
*/
class Solution {
public:
    int dfs(int i,int c,string& colors,vector<bool>& vis,vector<int>& memo,vector<vector<int>>& G){
        if(vis[i])  return -1;
        if(memo[i]>-1) return memo[i];
        vis[i]=true;
        int ans=(colors[i]-'a'==c);
        for(auto e:G[i]){
            int curres=dfs(e,c,colors,vis,memo,G);
            if(curres==-1)  return -1;
            if(colors[i]-'a'==c)    curres++;
            ans=max(ans,curres);
        }
        vis[i]=false;
        memo[i]=ans;
        return ans;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<vector<int>> G(n);
        vector<int> colorcnt(26);
        for(auto e:edges)   G[e[0]].push_back(e[1]);
        for(auto c:colors)  colorcnt[c-'a']++;
        vector<bool> vis(n,false);
        int ans=-1;
        for(int c=0;c<26;c++){
            if(c>0 && colorcnt[c]<=1){
                ans=max(ans,colorcnt[c]);
                continue;
            }
            vector<int> memo(n,-1);
            for(int i=0;i<n;i++){
                int curres=dfs(i,c,colors,vis,memo,G);
                if(curres==-1)  return -1;
                ans=max(ans,curres);
            }
        }
        return ans;
    }
};