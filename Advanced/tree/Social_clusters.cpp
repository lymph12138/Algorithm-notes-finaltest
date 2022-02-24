/*

*/
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 1010
int Father[maxn];
int IsRoot[maxn]={0};
int Course[maxn]={0};
int FindFather(int x){
    if(x!=Father[x])
        Father[x]=FindFather(Father[x]);
    return Father[x];
}
void Union(int a,int b){
    int FatherA=FindFather(a);
    int FatherB=FindFather(b);
    if(FatherA!=FatherB)
        Father[FatherA]=FatherB;
}
void Init(int n){
    for(int i=1;i<=n;i++){
        Father[i]=i;
        IsRoot[i]=0;
    }
}
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int n,num,temp;
    scanf("%d", &n);
    Init(n);
    for(int i=1;i<=n;i++){
        scanf("%d:",&num);
        for(int j=0;j<num;j++){
            scanf("%d",&temp);
            if(Course[temp]==0)
                Course[temp]=i;
            Union(i,FindFather(Course[temp]));
        }
    }
    for(int i=1;i<=n;i++)
        IsRoot[FindFather(i)]++;
    int ans=0;
    for(int i=1;i<=n;i++)
        if(IsRoot[i]!=0)
            ans++;
    printf("%d\n",ans);
    sort(IsRoot+1,IsRoot+n+1,cmp);
    for(int i=1;i<=ans;i++){
        printf("%d",IsRoot[i]);
        if(i!=ans)  printf(" ");
    }

    return 0;
}