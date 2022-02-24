/*

*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;
#define maxn 1010
vector <int> G[maxn];
bool vis[maxn];
int CurrentNode,n,m,k;
void DFS(int node){
    if(node==CurrentNode)   return ;
    vis[node]=true;
    for(int i=0;i<G[node].size();i++)
        if(vis[G[node][i]]==false)
            DFS(G[node][i]);
}
int main(){
    scanf("%d %d %d", &n, &m, &k);
    int a,b,tag;
    for(int i=0;i<m;i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int query=0;query<k;query++){
        scanf("%d", &CurrentNode);
        memset(vis,false,sizeof(vis));
        tag=0;
        for(int i=1;i<=n;i++){
            if(i!=CurrentNode && vis[i]==false){
                DFS(i);
                tag++;
            }
        }
        printf("%d\n", tag-1);
    }

    return 0;
}