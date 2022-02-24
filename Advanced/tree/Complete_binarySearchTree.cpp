/*

*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#define maxn 1010
using namespace std;
int origin[maxn],CBT[maxn],n,tag=0;
void InOrder(int root){
    if(root>n)  return ;
    InOrder(root*2);
    CBT[root]=origin[tag++];
    InOrder(root*2+1);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d", &origin[i]);
    sort(origin,origin+n);
    InOrder(1);
    for(int i=1;i<=n;i++)
        printf("%d%s",CBT[i],i==n?"":" ");

    return 0;
}
