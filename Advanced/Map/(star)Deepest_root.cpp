/*

*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
#define maxn 10010
int n,maxhigh=0;
vector<int>G[maxn];
bool vis[maxn]={0};
vector<int> tmp;
set<int> s;
void DFS(int node, int high){
    if(high>maxhigh){
        tmp.clear();
        tmp.push_back(node);
        maxhigh=high;
    }
    else if(high==maxhigh)
        tmp.push_back(node);
    vis[node]=true;
    for(int i=0;i<G[node].size();i++)
        if(vis[G[node][i]]==false)
            DFS(G[node][i],high+1);
}

int main(){
    int a,b;
    scanf("%d", &n);
    for(int i=0;i<n-1;i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int s1,count=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            DFS(i,1);
            if(i==1){
                if(tmp.size()!=0)
                    s1=tmp[0];
                for(int j=0;j<tmp.size();j++)
                    s.insert(tmp[j]);
            }
            count++;
        }
    }
    if(count>1)
        printf("Error: %d components",count);
    else{
        tmp.clear();
        maxhigh=0;
        memset(vis,false,sizeof(vis));
        DFS(s1,1);
        for(int i=0;i<tmp.size();i++)
            s.insert(tmp[i]);
        for(auto it=s.begin();it!=s.end();it++)
            printf("%d\n",*it);
    }

    return 0;
}