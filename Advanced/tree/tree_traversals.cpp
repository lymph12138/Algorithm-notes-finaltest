/*
give postorder and inorder, try to caculate level order.
2 3 1 5 7 6 4 postorder
1 2 3 4 5 6 7 inorder
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std; 
#define maxn 35
int N;
int post[maxn],in[maxn],pre[maxn];
struct treenode{
    int data;
    treenode *lchild;
    treenode *rchild;
};
treenode *create(int postL, int postR, int inL, int inR){
    if(postL>postR)
        return NULL;
    treenode *root=new treenode;
    root->data=post[postR];
    int k;
    for(k=inL;k<=inR;k++)
        if(in[k]==post[postR])
            break;
    root->lchild=create(postL,postL+k-inL-1,inL,k-1);
    root->rchild=create(postL+k-inL,postR-1,k+1,inR);
    return root;
}
int num=0;
void BFS(treenode *root){
    queue<treenode*> q;
    q.push(root);
    while(!q.empty()){
        treenode *temp=q.front();
        q.pop();
        printf("%d",temp->data);
        num++;
        if(num<N)
            printf(" ");
        if(temp->lchild!=NULL)
            q.push(temp->lchild);
        if(temp->rchild!=NULL)
            q.push(temp->rchild);
    }
}
int main(){
    scanf("%d", &N);
    for(int i=0;i<N;i++)
        scanf("%d", &post[i]);
    for(int i=0;i<N;i++)
        scanf("%d", &in[i]);
    treenode* root=create(0,N-1,0,N-1);
    BFS(root);
    
    return 0;
}