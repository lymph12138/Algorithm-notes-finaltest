/*

*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 100010
struct Node{
    int address,next,flag,key;
}node[maxn];
bool cmp(Node a, Node b){
    if(a.flag==0 || b.flag==0)
        return a.flag>b.flag;
    else
        return a.key<b.key;
}
int main(){
    int N,address,next, key;
    scanf("%d %d", &N, &address);
    int temp=address;
    for(int i=0;i<maxn;i++)
        node[i].flag=false;
    for(int i=0;i<N;i++){
        scanf("%d %d %d", &address, &key, &next);
        node[address].address=address;
        node[address].key=key;
        node[address].next=next;
    }
    int count=0;
    while(temp!=-1){
        node[temp].flag=true;
        count++;
        temp=node[temp].next;
    }
    if(count==0)
        printf("0 -1");
    else{
        sort(node, node+maxn,cmp);
        printf("%d %05d\n",count,node[0].address);
        for(int i=0;i<count;i++){
            if(i==count-1)
                printf("%05d %d -1\n",node[i].address,node[i].key);
            else
                printf("%05d %d %05d\n",node[i].address, node[i].key,node[i+1].address);
        }
    }
    
    return 0;
}