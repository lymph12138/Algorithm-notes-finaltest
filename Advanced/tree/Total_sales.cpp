/*

*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define maxn 100010
int n;
double P,r,ans=0;
struct treenode{
    double data;
    vector<int> child;
}TreeNode[maxn];
void DFS(int root,int high){
    if(TreeNode[root].child.size()==0){
        ans +=TreeNode[root].data*pow(1+r,high);
        return ;
    }
    for(int i=0;i<TreeNode[root].child.size();i++)
        DFS(TreeNode[root].child[i],high+1);
}
int main(){
    int k,child;
    scanf("%d %lf %lf", &n, &P, &r);
    r/=100;
    for(int i=0;i<n;i++){
        scanf("%d", &k);
        if(k==0)
            scanf("%lf", &TreeNode[i].data);
        else{
            for(int j=0;j<k;j++){
                scanf("%d",&child);
                TreeNode[i].child.push_back(child);
            }
        }
    }
    DFS(0,0);
    printf("%.1lf",P*ans);

    return 0;
}
