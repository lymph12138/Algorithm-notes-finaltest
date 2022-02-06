/*
give integers N and D1, D2,...,DN, Di means distance from i-th to i+1-th
give integer M and following M lines.
try to caculate the miniest distance between i-th and j-th.
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
int main(){
    int N,dist=0;
    scanf("%d", &N);
    int D[N+1]={0};
    for(int i=1;i<N+1;i++){
        scanf("%d", &D[i]);
        dist=dist+D[i];
        D[i]=dist;
    }
    int M;
    scanf("%d", &M);
    for(int i=0;i<M;i++){
        int k=0,l=0;
        scanf("%d %d", &k, &l);
        int temp=0,tempdist=0;
        if(k>l){
            temp=k;
            k=l;
            l=temp;
        }
        tempdist=D[l-1]-D[k-1];
        if(tempdist<dist-tempdist)
            printf("%d\n", tempdist);
        else
            printf("%d\n", dist-tempdist);
    }

    return 0;
}