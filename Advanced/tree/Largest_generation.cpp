/*
DFS
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
int n,m,chi,temp,id;
#define maxn 110
vector <int> child[maxn];
int HashTable[maxn]={0};
int maxchild=0,maxhigh=0;
void DFS(int root, int high){
    HashTable[high]++;
    for(int i=0;i<child[root].size();i++)
        DFS(child[root][i],high+1);
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++){
        scanf("%d %d", &id, &chi);
        for(int j=0;j<chi;j++){
            scanf("%d", &temp);
            child[id].push_back(temp);
        }
    }
    DFS(1,1);
    for(int i=1;i<maxn;i++){
        if(HashTable[i]>maxchild){
            maxchild=HashTable[i];
            maxhigh=i;
        }
    }
    printf("%d %d",maxchild,maxhigh);

    return 0;
}