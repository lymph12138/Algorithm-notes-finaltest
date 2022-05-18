#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
private:
    vector<int> root;
    vector<vector<int>> move={{1,0},{-1,0},{0,1},{0,-1}};
    int find(int i){
        if(root[i]<0 || root[i]==i)   return i;
        root[i]=find(root[i]);
        return root[i];
    }
    void combine(int i,int j){
        int rootofi=find(i);
        int rootofj=find(j);
        root[rootofi]=rootofj;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n=cells.size();
        root=vector<int>(n+2,-1);
        int top=0,bottom=n+1;
        vector<vector<int>> grid(row,vector<int>(col,1));
        for(int idx=n-1;idx>=0;idx--){
            int i=cells[idx][0]-1,j=cells[idx][1]-1;
            grid[i][j]=0;
            int pos=i*col+j+1;
            if(pos<=col)    combine(pos,top);
            if(pos>n-col)   combine(pos,bottom);
            for(int k=0;k<move.size();k++){
                int x=i+move[k][0],y=j+move[k][1];
                if(x<0 || x>=row || y<0 || y>=col)  continue;
                if(grid[x][y]==1)   continue;
                combine(pos,x*col+y+1);
            }
            if(find(top)==find(bottom)) return idx;
        }
        return -1;
    }
};

int main(){
    int row=3,col=3;
    vector<vector<int>> cells={{1,2},{2,1},{3,3},{2,2},{1,1},{1,3},{2,3},{3,2},{3,1}};
    cout<<Solution().latestDayToCross(row,col,cells);

    return 0;
}