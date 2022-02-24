/*

*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define maxn 510
#define inf 999
int Cmax, N, Sp, M;
int sent=inf;
int collect=inf;
int weight[maxn],G[maxn][maxn],dist[maxn];
bool vis[maxn];
vector<int>PathList[maxn];
void Dijkstra(int node){
    fill(dist,dist+maxn,inf);
    fill(vis,vis+maxn,false);
    dist[node]=0;
    while(!vis[Sp]){
        int v=-1;
        int min=inf;
        for(int i=0;i<=N;i++){
            if(!vis[i] && dist[i]<min){
                min=dist[i];
                v=i;
            }
        }
        if(v==-1)   break;
        vis[v]=true;
        for(int w=0;w<=N;w++){
            if(G[v][w]!=inf && !vis[w] && dist[v]+G[v][w]<dist[w]){
                dist[w]=dist[v]+G[v][w];
                PathList[w].clear();
                PathList[w].push_back(v);
            }
            else if(G[v][w]!=inf &&!vis[w] && dist[v]+G[v][w]==dist[w])
                PathList[w].push_back(v);
        }
    }
}
vector<int>CurrentPath,path;
void DFS(int node){
    if(node==0){
        int CurrentSent=0;
        int CurrentCollect=0;
        for(int i=CurrentPath.size()-1;i>=0;i--){
            if(weight[CurrentPath[i]]>=0)
                CurrentCollect+=weight[CurrentPath[i]];
            else{
                if(CurrentCollect>abs(weight[CurrentPath[i]]))
                    CurrentCollect+=weight[CurrentPath[i]];
                else{
                    CurrentSent+=abs(weight[CurrentPath[i]])-CurrentCollect;
                    CurrentCollect=0;
                }
            }
        }
        CurrentPath.push_back(node);
        if(CurrentSent<sent){
            sent=CurrentSent;
            collect=CurrentCollect;
            path=CurrentPath;
        }
        else if(CurrentSent==sent && CurrentCollect<collect){
            collect=CurrentCollect;
            path=CurrentPath;
        }
        CurrentPath.pop_back();
    }
    CurrentPath.push_back(node);
    for(int i=0;i<PathList[node].size();i++)
        DFS(PathList[node][i]);
    CurrentPath.pop_back();
}
int main(){
    int Si,Sj,Tij;
    fill(G[0],G[0]+maxn*maxn,inf);
    fill(weight,weight+maxn,0);
    scanf("%d %d %d %d", &Cmax, &N, &Sp, &M);
    for(int i=1;i<=N;i++){
        scanf("%d", &weight[i]);
        weight[i]-=Cmax/2;
    }
    for(int i=0;i<M;i++){
            scanf("%d %d %d", &Si, &Sj, &Tij);
            G[Si][Sj]=Tij;
            G[Sj][Si]=Tij;
    }
    Dijkstra(0);
    DFS(Sp);
    printf("%d %d",sent,path[path.size()-1]);
    for(int i=path.size()-2;i>=0;i--)
        printf("->%d",path[i]);
    printf(" %d",collect);

    return 0;
}