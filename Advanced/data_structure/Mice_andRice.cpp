/*
the first line contains two positive integers: NP and NG
the second line contains NP distinct non-negative numbers Wi
the third line contains the initial playing order
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
#define maxn 1010
struct mouse{
    int weight,rank;
}mouse[maxn];


int main(){
    int NP, NG, temp;
    scanf("%d %d", &NP, &NG);
    for(int i=0;i<NP;i++){
        scanf("%d", &temp);
        mouse[i].weight=temp;
    }
    queue <int> q;
    for(int i=0;i<NP;i++){
        scanf("%d", &temp);
        q.push(temp);
    }

    temp=NP;
    int group;
    while(q.size()!=1){
        if(temp%NG==0)  group=temp/NG;
        else    group=temp/NG+1;
        for(int i=0;i<group;i++){
            int kMice=q.front();
            for(int j=0;j<NG;j++){
                if(i*NG+j>=temp)    break;
                int frontMice=q.front();
                if(mouse[frontMice].weight>mouse[kMice].weight)
                    kMice=frontMice;
                mouse[frontMice].rank=group+1;
                q.pop();
            }
            q.push(kMice);
        }
        temp=group;
    }
    mouse[q.front()].rank=1;
    for(int i=0;i<NP;i++){
        printf("%d", mouse[i].rank);
        if(i<NP-1)  printf(" ");
    }

    return 0;
}