/*

*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
#define maxn 2010
int e[maxn][maxn],weight[maxn];
bool vis[maxn];
map<string,int> StringToInt;
map<int,string> IntToString;
map<string,int> ans;
int k,idnumber=1;
int head,members,total;
int stoifun(string s){
    if(StringToInt[s]==0){
        StringToInt[s]=idnumber;
        IntToString[idnumber]=s;
        return idnumber++;
    }
    return StringToInt[s];
}
void DFS(int node,int &head,int &members,int &total){
    vis[node]=true;
    members++;
    if(weight[node]>weight[head])
        head=node;
    for(int i=1;i<idnumber;i++){
        if(e[node][i]>0){
            total+=e[node][i];
            e[node][i]=0;
            e[i][node]=0;
            if(vis[i]==false)
                DFS(i,head,members,total);
        }
    }
}
void DFSTravel(){
    for(int i=1;i<idnumber;i++){
        head=i;
        members=0;
        total=0;
        DFS(i,head,members,total);
        if(members>2 && total>k)
            ans[IntToString[head]]=members;
    }
}
int main(){
    fill(e[0],e[0]+maxn*maxn,0);
    memset(weight,0,sizeof(weight));
    memset(vis,false,sizeof(vis));
    int n,w;
    cin>>n>>k;
    string s1,s2;
    for(int i=0;i<n;i++){
        cin>>s1>>s2>>w;
        e[stoifun(s1)][stoifun(s2)]+=w;
        e[stoifun(s2)][stoifun(s1)]+=w;
        weight[stoifun(s1)]+=w;
        weight[stoifun(s2)]+=w;
    }
    DFSTravel();
    printf("%d\n",ans.size());
    for(auto it=ans.begin();it!=ans.end();it++)
        cout<<it->first<<" "<<it->second<<"\n";

    return 0;
}
