/*
1368
*/
class Solution {
public:
    vector<vector<int>> move={{0,1},{0,-1},{1,0},{-1,0}};
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int> dist(n*m,INT_MAX);
        dist[0]=0;
        deque<int> q;
        q.push_back(0);
        while(q.size()){
            int v=q.front();q.pop_front();
            for(int k=0;k<4;k++){
                int x=v/m+move[k][0];
                int y=v%m+move[k][1];
                int w=(grid[v/m][v%m]!=k+1),u=x*m+y;
                if(x<0 || x>=n || y<0 || y>=m)  continue;
                if(dist[v]+w<dist[u]){
                    dist[u]=w+dist[v];
                    if(w==1)    q.push_back(u);
                    else    q.push_front(u);
                }
            }
        }
        return dist.back();
    }
};