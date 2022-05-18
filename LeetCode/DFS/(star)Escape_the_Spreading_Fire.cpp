/*
2258
*/
class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int MaxTime=1e9;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> time(n,vector<int>(m,MaxTime));
        queue<pair<int,int>> fire;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    fire.push({i,j});
                    time[i][j]=0;
                }
            }
        }
        int timeline=0;
        vector<vector<int>> move={{1,0},{-1,0},{0,1},{0,-1}};
        while(fire.size()){
            if(time[n-1][m-1]<MaxTime)  break;
            timeline++;
            int size=fire.size();
            for(int k=0;k<size;k++){
                auto [i,j]=fire.front();
                fire.pop();
                for(int l=0;l<4;l++){
                    int x=i+move[l][0];
                    int y=j+move[l][1];
                    if(x<0 || x>=n || y<0 || y>=m || grid[x][y]==2)  continue;
                    if(time[x][y]>timeline){
                        time[x][y]=timeline;
                        fire.push({x,y});
                    }
                }
            }
        }
        priority_queue<array<int,3>>  q;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        q.push({time[n-1][m-1],n-1,m-1});
        while(q.size()){
            auto [ti,i,j]=q.top();
            vis[i][j]=true;
            q.pop();
            if(ti<0)    break;
            if(i==0 && j==0){
                return ti>1e5?MaxTime:ti;
            }
            for(int l=0;l<4;l++){
                int x=i+move[l][0];
                int y=j+move[l][1];
                if(x<0 || x>=n || y<0 || y>=m || vis[x][y] || grid[x][y]!=0)  continue;
                q.push({min(ti,time[x][y])-1,x,y});
            }
        }
        return -1;
    }
};