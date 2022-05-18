    /*
    803
    */
    class Solution {
    private:
        vector<vector<int>> grid;
        int n,m;
        int dfs(int x,int y){
            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1){
                grid[x][y]=2;
                int ans=1+dfs(x-1,y)+dfs(x+1,y)+dfs(x,y-1)+dfs(x,y+1);
                return ans;
            }
            return 0;
        }
        bool IsStable(int x,int y){
            if(x==0)    return true;
            if(x+1<n && grid[x+1][y]==2)    return true;
            if(x-1>=0 && grid[x-1][y]==2)    return true;
            if(y+1<m && grid[x][y+1]==2)    return true;
            if(y-1>=0 && grid[x][y-1]==2)    return true;
            return false;
        }
    public:
        vector<int> hitBricks(vector<vector<int>>& passgrid, vector<vector<int>>& hits) {
            grid=passgrid;
            n=grid.size(),m=grid[0].size();
            for(auto hit:hits)    grid[hit[0]][hit[1]]--;
            for(int i=0;i<m;i++)    dfs(0,i);
            int l=hits.size();
            vector<int> ans(l,0);
            for(int i=l-1;i>=0;i--){
                int x=hits[i][0],y=hits[i][1];
                grid[x][y]++;
                if(IsStable(x,y) && grid[x][y]==1)  ans[i]=dfs(x,y)-1;
            }
            return ans;
        }
    };