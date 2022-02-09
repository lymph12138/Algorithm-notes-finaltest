/*

*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    int address,next,flag;
}node[200010];
#define move 100000
int main(){
    int N,address,next, key;
    scanf("%d %d", &N, &address);
    int temp=address;
    for(int i=0;i<2*move;i++)
        node[i].flag=0;
    for(int i=0;i<N;i++){
        scanf("%d %d %d", &address, &key, &next);
        node[key+move].address=address;
        node[key+move].next=next;
        node[key+move].flag=1;
    }
    printf("%05d", temp);
    for(int i=0;i<2*move;i++){
        if(node[i].flag==1){
            printf(" %d %05d\n %05d",i-move,node[i].address);
            temp=i;
        }
    }
    printf(" %d -1",temp);

    return 0;
}