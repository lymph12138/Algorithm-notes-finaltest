/*

*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct node{
    int data,high;
    node *lchild,*rchild;
}*root;
node* NewNode(int data){
    node *Node=new node;
    Node->data=data;
    Node->lchild=NULL;
    Node->rchild=NULL;
    Node->high=1;
    return Node;
}
int GetHigh(node* root){
    if(root==NULL)  return 0;
    else    return root->high;
}
void UpdateHigh(node*root){
    root->high=max(GetHigh(root->lchild),GetHigh(root->rchild))+1;
}
int GetBalanceFactor(node* root){
    return GetHigh(root->lchild)-GetHigh(root->rchild);
}
void L(node* &root){
    node* temp=root->rchild;
    root->rchild=temp->lchild;
    temp->lchild=root;
    UpdateHigh(root);
    UpdateHigh(temp);
    root=temp;
}
void R(node* &root){
    node* temp=root->lchild;
    root->lchild=temp->rchild;
    temp->rchild=root;
    UpdateHigh(root);
    UpdateHigh(temp);
    root=temp;
}
void Insert(node* &root,int data){
    if(root==NULL){
        root=NewNode(data);
        return ;
    }
    if(data<root->data){
        Insert(root->lchild,data);
        UpdateHigh(root);
        if(GetBalanceFactor(root)==2){
            if(GetBalanceFactor(root->lchild)==1)
                R(root);
            else if(GetBalanceFactor(root->lchild)==-1){
                L(root->lchild);
                R(root);
            }
        }
    }
    else{
        Insert(root->rchild,data);
        UpdateHigh(root);
        if(GetBalanceFactor(root)==-2){
            if(GetBalanceFactor(root->rchild)==-1)
                L(root);
            else if(GetBalanceFactor(root->rchild)==1){
                R(root->rchild);
                L(root);
            }
        }
    }
}
node *Create(int data[],int n){
    node* root=NULL;
    for(int i=0;i<n;i++)
        Insert(root,data[i]);
    return root;
}
#define maxn 25
int main(){ 
    int data[maxn],n;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d", &data[i]);
    node* root=Create(data,n);
    printf("%d",root->data);

    return 0;
}