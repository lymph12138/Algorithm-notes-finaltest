/*

*/
#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define maxn 510
#define inf 99999
int N, M, S, D, G[maxn][maxn],cost[maxn][maxn],dist[maxn];
bool vis[maxn];
vector<int> PathList[maxn],CurrentPath,Path;
int mincost=inf;
void Dijkstra(int node){
    fill(vis,vis+maxn,false);
    fill(dist,dist+maxn,inf);
    dist[node]=0;
    for(int tag=0;tag<N;tag++){
        int v=-1;
        int min=inf;
        for(int i=0;i<N;i++){
            if(!vis[i] && dist[i]<min){
                min=dist[i];
                v=i;
            }
        }
        if(v==-1)   break;
        vis[v]=true;
        for(int w=0;w<N;w++){
            if(G[v][w]!=inf && !vis[w] && dist[v]+G[v][w]<dist[w]){
                PathList[w].clear();
                dist[w]=dist[v]+G[v][w];
                PathList[w].push_back(v);
            }
            else if(G[v][w]!=inf && !vis[w] && dist[v]+G[v][w]==dist[w])
                PathList[w].push_back(v);
        }
    }
}
void DFS(int node){
    CurrentPath.push_back(node);
    if(node==S){
        int currentcost=0;
        for(int i=CurrentPath.size()-1;i>0;i--){
            int id=CurrentPath[i];
            int nextid=CurrentPath[i-1];
            currentcost+=cost[id][nextid];
        }
        if(currentcost<mincost){
            mincost=currentcost;
            Path=CurrentPath;
        }
        CurrentPath.pop_back();
        return ;
    }
    for(int i=0;i<PathList[node].size();i++)
        DFS(PathList[node][i]);
    CurrentPath.pop_back();
}
int main(){
    int v1,v2,temp1,temp2;
    scanf("%d %d %d %d", &N, &M, &S, &D);
    fill(G[0],G[0]+maxn*maxn,inf);
    fill(cost[0],cost[0]+maxn*maxn,0);
    for(int i=0;i<M;i++){
        scanf("%d %d %d %d", &v1, &v2, &temp1, &temp2);
        G[v1][v2]=temp1;
        G[v2][v1]=temp1;
        cost[v1][v2]=temp2;
        cost[v2][v1]=temp2;
    }
    Dijkstra(S);
    DFS(D);
    for(int i=Path.size()-1;i>=0;i--)
        printf("%d ", Path[i]);
    printf("%d %d",dist[D],mincost);

    return 0;
}