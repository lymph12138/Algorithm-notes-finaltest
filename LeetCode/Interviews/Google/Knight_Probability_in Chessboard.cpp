/*
688
*/

class Solution {
private:
    vector<pair<int,int>> jumps{{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2}};
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> dp1(n,vector<double>(n,1));
        while(--k>=0){
            vector<vector<double>> dp2(n,vector<double>(n,0));
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dp1[i][j]==0)    continue;
                    double p=dp1[i][j]/8.0;
                    for(auto [r,c]:jumps)
                        if(i+r>=0 && i+r<n && j+c>=0 && j+c<n)
                            dp2[i+r][j+c]+=p;
                }
            }
            swap(dp1,dp2);
        }
    return dp1[row][column];
    }
};