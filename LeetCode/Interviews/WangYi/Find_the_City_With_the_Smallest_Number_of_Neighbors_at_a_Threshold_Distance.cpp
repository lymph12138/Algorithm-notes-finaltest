/*
1334
use of memset function? 
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int D[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                D[i][j]=1000000;
        for(int i=0;i<n;i++)    D[i][i]=0;
        for(int i=0;i<edges.size();i++){
            D[edges[i][0]][edges[i][1]]=edges[i][2];
            D[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(D[i][k]+D[k][j]<D[i][j]){
                        D[i][j]=D[i][k]+D[k][j];
                    }
                }
            }
        }
        vector<vector<int>> ans;
        vector<int> temp;
        for(int i=0;i<n;i++){
            temp.clear();
            for(int j=0;j<n;j++){
                if(i==j)    continue;
                if(D[i][j]<=distanceThreshold)
                    temp.push_back(j);
            }
            ans.push_back(temp);
        }
        int res=n-1;
        int min=ans[res].size();
        for(int i=n-1;i>=0;i--){
            if(ans[i].size()<min){
                res=i;
                min=ans[i].size();
            }
        }
        return res;
    }
};

int main(){
    int n=5;
    vector<vector<int>> edges={{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}};
    int distance=2;
    cout<<Solution().findTheCity(n,edges,distance);

    return 0;
}
