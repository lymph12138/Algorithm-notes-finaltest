/*

*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
#define maxn 1030
#define inf 99999
int N,M,K,Ds;
int G[maxn][maxn],dist[maxn],path[maxn];
bool vis[maxn];
void Dijkstra(int node){
    fill(vis,vis+maxn,false);
    fill(dist,dist+maxn,inf);
    fill(path,path+maxn,-1);
    dist[node]=0;
    for(int tag=1;tag<=N+M;tag++){
        int v=-1;
        int min=inf;
        for(int i=1;i<=N+M;i++){
            if(!vis[i] && dist[i]<min){
                v=i;
                min=dist[i];
            }
        }
        if(v==-1)   break;
        vis[v]=true;
        for(int w=1;w<=N+M;w++){
            if(!vis[w] && G[v][w]!=inf && dist[v]+G[v][w]<dist[w]){
                dist[w]=G[v][w]+dist[v];
                path[w]=v;
            }
        }
    }
}
int GetId(char str[]){
    int i=0,len=strlen(str),id=0;
    while(i<len){
        if(str[i]!='G')
            id=id*10+str[i]-'0';
        i++;
    }
    if(str[0]=='G') return N+id;
    else return id;
}
int main(){
    char city1[5],city2[5];
    int temp,u,v;
    scanf("%d %d %d %d", &N, &M, &K, &Ds);
    fill(G[0],G[0]+maxn*maxn,inf);
    for(int i=0;i<K;i++){
        cin>>city1>>city2>>temp;
        u=GetId(city1);
        v=GetId(city2);
        G[u][v]=temp;
        G[v][u]=temp;
    }
    double ansDis=-1,ansAvg=inf;
    int ansId=-1;
    for(int i=N+1;i<=N+M;i++){
        double minDis=inf,avg=0;
        Dijkstra(i);
        for(int j=1;j<=N;j++){
            if(dist[j]>Ds){
                minDis=-1;
                break;
            }
            if(dist[j]<minDis)  minDis=dist[j];
            avg+=1.0*dist[j]/N;
        }
        if(minDis==-1)  continue;
        if(minDis>ansDis){
            ansId=i;
            ansDis=minDis;
            ansAvg=avg;
        }
        else if(minDis==ansDis && avg<ansAvg){
            ansId=i;
            ansAvg=avg;
        }
    }
    if(ansId==-1)   printf("No Solution");
    else    printf("G%d\n%.1f %.1f",ansId-N,ansDis,ansAvg);

    return 0;
}