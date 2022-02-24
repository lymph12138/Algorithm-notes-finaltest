/*

*/
#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n,l;
#define maxn 1010
struct node{
    int id,level;
};
vector<node>G[maxn];
bool inq[maxn]={0};
void BFS(int root){
    int count=0;
    queue<node> Q;
    node start;
    start.id=root;
    start.level=0;
    Q.push(start);
    inq[start.id]=true;
    while(!Q.empty()){
        node top=Q.front();
        Q.pop();
        for(int i=0;i<G[top.id].size();i++){
            node next=G[top.id][i];
            next.level=top.level+1;
            if(inq[next.id]==false && next.level<=l){
                Q.push(next);
                inq[next.id]=true;
                count++;
            }
        }
    }
    printf("%d\n",count);
}

int main(){
    cin>>n>>l;
    int temp,a,num;
    node user;
    for(int i=1;i<=n;i++){
        scanf("%d", &temp);
        user.id=i;
        for(int j=0;j<temp;j++){
            scanf("%d", &a);
            G[a].push_back(user);
        }
    }
    cin>>num;
    for(int i=0;i<num;i++){
        memset(inq,false,sizeof(inq));
        scanf("%d", &a);
        BFS(a);
    }

    return 0;
}