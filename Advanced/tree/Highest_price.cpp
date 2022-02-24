/*

*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define maxn 100010
vector <int> child[maxn];
int n,num=0,maxhigh=0;
double P,r;

void DFS(int root, int high){
    if(child[root].size()==0){
        if(high>maxhigh){
            maxhigh=high;
            num=1;
        }
        else if(high==maxhigh)
            num++;
        return ;
    }
    for(int i=0;i<child[root].size();i++)
        DFS(child[root][i],high+1);
}

int main(){
    scanf("%d %lf %lf", &n, &P, &r);
    r/=100;
    int father,root;
    for(int i=0;i<n;i++){
        scanf("%d", &father);
        if(father!=-1)
            child[father].push_back(i);
        else    root=i;
    }
    DFS(root,0);
    printf("%.2lf %d",P*pow(1+r,maxhigh),num);

    return 0;
}