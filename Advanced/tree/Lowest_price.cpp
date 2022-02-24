/*
A1106
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
#define maxn 100010
int num=0,n,chi,temp,minhigh=maxn;
double P,r;
vector <int> child[maxn];
void DFS(int root, int high){
    if(child[root].size()==0){
        if(minhigh>high){
            minhigh=high;
            num=1;
        }
        else if(minhigh==high)
            num++;
        return ;
    }
    for(int i=0;i<child[root].size();i++)
        DFS(child[root][i],high+1);
}
int main(){
    scanf("%d %lf %lf", &n, &P, &r);
    r/=100;
    for(int i=0;i<n;i++){
        scanf("%d", &chi);
        if(chi!=0){
            for(int j=0;j<chi;j++){
                scanf("%d", &temp);
                child[i].push_back(temp);
            }
        }
    }
    DFS(0,0);
    printf("%.04lf %d", P*pow(1+r,minhigh),num);

    return 0;
}