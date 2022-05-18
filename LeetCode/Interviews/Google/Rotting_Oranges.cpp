/*
994
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int count=0;
        queue<pair<int,int>> rotten;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    count++;
                else if(grid[i][j]==2)
                    rotten.push({i,j});
            }
        }
        vector<vector<int>> move={{1,0},{-1,0},{0,1},{0,-1}};
        int ans=0;
        while(rotten.size() && count){
            ans++;
            int size=rotten.size();
            for(int k=0;k<size;k++){
                auto [i,j]=rotten.front();
                for(int l=0;l<4;l++){
                    int x=i+move[l][0];
                    int y=j+move[l][1];
                    if(x<0 || x>=n || y<0 || y>=m)  continue;
                    if(grid[x][y]==1){
                        rotten.push({x,y});
                        grid[x][y]=2;
                        count--;
                    }
                }
                rotten.pop();
            }
        }
        if(count)   return -1;
        else    return ans;
    }
};