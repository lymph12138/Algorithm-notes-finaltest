/*
create a binary tree and print levelorder and inorder.
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

#define maxn 15
bool NotRoot[maxn]={false};
struct treenode{
    int lchild, rchild;
}TreeNode[maxn];
int StrToNum(char c){
    if(c=='-')
        return -1;
    else{
        NotRoot[c-'0']=true;
        return c-'0';
    }
}
int n,num=0;
void print(int id){
    printf("%d",id);
    num++;
    if(num<n)
        printf(" ");
    else
        printf("\n");
}
void PostOrder(int root){
    if(root==-1)
        return ;
    PostOrder(TreeNode[root].lchild);
    PostOrder(TreeNode[root].rchild);
    swap(TreeNode[root].lchild,TreeNode[root].rchild);
}
void LevelOrder(int root){
    queue<int> Q;
    Q.push(root);
    while(!Q.empty()){
        int now=Q.front();
        print(now);
        Q.pop();
        if(TreeNode[now].lchild!=-1)
            Q.push(TreeNode[now].lchild);
        if(TreeNode[now].rchild!=-1)
            Q.push(TreeNode[now].rchild);
    }
}
void InOrder(int root){
    if(TreeNode[root].lchild!=-1)
        InOrder(TreeNode[root].lchild);
    print(root);
    if(TreeNode[root].rchild!=-1)
        InOrder(TreeNode[root].rchild);
}
int FindRoot(){
    for(int i=0;i<n;i++)
        if(NotRoot[i]==false)
            return i;
}

int main(){
    scanf("%d", &n);
    char left,right;
    for(int i=0;i<n;i++){
        cin>>left>>right;
        TreeNode[i].lchild=StrToNum(left);
        TreeNode[i].rchild=StrToNum(right);
    }
    int root=FindRoot();
    PostOrder(root);
    LevelOrder(root);
    num=0;
    InOrder(root);

    return 0;
}


