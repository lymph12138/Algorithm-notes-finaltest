/*

*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <queue>
using namespace std;
#define maxn 110
struct Node{
    int lchild,rchild,data;
}node[maxn];
int n,number[maxn],num=0;
void InOrder(int root){
    if(root==-1)    return ;
    InOrder(node[root].lchild);
    node[root].data=number[num++];
    InOrder(node[root].rchild);
}
void LevelOrder(int root){
    queue<int> Q;
    Q.push(root);
    num=0;
    while(!Q.empty()){
        int temp=Q.front();
        Q.pop();
        printf("%d",node[temp].data);
        num++;
        if(num<n)   printf(" ");
        if(node[temp].lchild!=-1)
            Q.push(node[temp].lchild);
        if(node[temp].rchild!=-1)
            Q.push(node[temp].rchild);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %d",&node[i].lchild,&node[i].rchild);
    for(int i=0;i<n;i++)
        scanf("%d",&number[i]);
    sort(number,number+n);
    InOrder(0);
    LevelOrder(0);

    return 0;
}