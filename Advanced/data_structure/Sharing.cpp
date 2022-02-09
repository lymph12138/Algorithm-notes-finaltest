/*
try to find the common str of two english words.
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct node{
    char data;
    int next;
    bool flag;
}node[100010];

int main(){
    int s1,s2,n;
    scanf("%d %d %d", &s1, &s2, &n);
    int ad,ne;
    char da;
    for(int i=0;i<n;i++){
        scanf("%d %c %d", &ad, &da, &ne);
        node[ad].data=da;
        node[ad].next=ne;
        node[ad].flag=false;
    }
    int temp=s1;
    while(temp!=-1){
        node[temp].flag=true;
        temp=node[temp].next;
    }
    temp=s2;
    while(temp!=-1){
        if(node[temp].flag==true){
            printf("%05d", temp);
            return 0;
        }
        temp=node[temp].next;
    }
    printf("-1");

    return 0;
}