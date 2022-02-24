/*

*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define maxn 510
#define inf 999999
int dist[maxn],weight[maxn],path[maxn],G[maxn][maxn],num[maxn];
int n,m,st,ed;
bool vis[maxn];
void Dijkstra(int root){
    fill(dist,dist+maxn,inf);
    memset(weight,0,sizeof(weight));
    memset(num,0,sizeof(num));
    memset(vis,false,sizeof(vis));
    memset(path,-1,sizeof(path));
    dist[root]=0;
    num[root]=1;
    weight[root]=G[root][root];
    int v,w;
    while(1){
        v=-1;
        int minv=inf;
        for(int i=0;i<n;i++){
            if(!vis[i] && dist[i]<minv){
                v=i;
                minv=dist[i];
            }
        }
        if(v==-1)   break;
        vis[v]=true;
        for(w=0;w<n;w++){
            if(!vis[w] && G[v][w]!=inf){
                if(dist[v]+G[v][w]<dist[w]){
                    dist[w]=dist[v]+G[v][w];
                    path[w]=v;
                    num[w]=num[v];
                    weight[w]=weight[v]+G[w][w];
                }
                else if(dist[v]+G[v][w]==dist[w]){
                    num[w]+=num[v];
                    path[w]=v;
                    if(weight[v]+G[w][w]>weight[w])
                        weight[w]=weight[v]+G[w][w];
                }
            }
        }
    }
}
int main(){
    scanf("%d %d %d %d", &n, &m, &st, &ed);
    fill(G[0],G[0]+maxn*maxn,inf);
    int c1,c2,temp;
    for(int i=0;i<n;i++)
        scanf("%d", &G[i][i]);
    for(int i=0;i<m;i++){
        scanf("%d %d %d", &c1, &c2, &temp);
        G[c1][c2]=temp;
        G[c2][c1]=temp;
    }
    Dijkstra(st);
    printf("%d %d", num[ed],weight[ed]);

    return 0;
}