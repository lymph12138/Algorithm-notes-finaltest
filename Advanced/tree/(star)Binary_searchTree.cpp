/*

*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> origin,pre,prem,post,postm;
struct node{
    int data;
    node *left,*right;
};

void Insert(node* &root,int data){
    if(root==NULL){
        root=new node;
        root->data=data;
        root->left=NULL;
        root->right=NULL;
        return ;
    }
    if(data<root->data) Insert(root->left,data);
    else    Insert(root->right,data);
}
void PreOrder(node *root,vector<int> &vi){
    if(root==NULL)  return;
    vi.push_back(root->data);
    PreOrder(root->left,vi);
    PreOrder(root->right,vi);
}
void MirrorPreOrder(node *root,vector<int> &vi){
    if(root==NULL)  return ;
    vi.push_back(root->data);
    MirrorPreOrder(root->right,vi);
    MirrorPreOrder(root->left,vi);
}
void PostOrder(node *root,vector<int> &vi){
    if(root==NULL)  return ;
    PostOrder(root->left,vi);
    PostOrder(root->right,vi);
    vi.push_back(root->data);

}
void MirrorPostOrder(node *root,vector<int> &vi){
    if(root==NULL)  return ;
    MirrorPostOrder(root->right,vi);
    MirrorPostOrder(root->left,vi);
    vi.push_back(root->data);
}

int n,temp;
int main(){
    scanf("%d", &n);
    node *root=NULL;
    for(int i=0;i<n;i++){
        scanf("%d", &temp);
        origin.push_back(temp);
        Insert(root,temp);
    }
    PreOrder(root,pre);
    MirrorPreOrder(root,prem);
    PostOrder(root,post);
    MirrorPostOrder(root,postm);
    if(pre==origin){
        printf("YES\n");
        for(int i=0;i<post.size();i++)
            printf("%d%s",post[i],i==post.size()-1?"":" ");
    }
    else if(prem==origin){
        printf("YES\n");
        for(int i=0;i<postm.size();i++)
            printf("%d%s", postm[i],i==postm.size()-1?"":" ");

    }
    else    printf("NO");
    
    return 0;
}