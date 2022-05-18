/*
1139
*/

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> left(n,vector<int>(m,0)),top(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                left[i][j]=grid[i][j]+(j&&grid[i][j]?left[i][j-1]:0);
                top[i][j]=grid[i][j]+(i&&grid[i][j]?top[i-1][j]:0);
            }
        }
        for(int l=min(m,n);l>0;l--)
            for(int i=0;i<n-l+1;i++)
                for(int j=0;j<m-l+1;j++)
                    if(min({top[i+l-1][j],top[i+l-1][j+l-1],
                    left[i][j+l-1],left[i+l-1][j+l-1]})>=l)
                        return l*l;
        return 0;
    }
};

