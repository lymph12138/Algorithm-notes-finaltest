/*
give any permutation of the numbers{0,1,2,...,N-1}, only accepts swap(0,*)
try to caculate the minimum steps need to sort the given permutation
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 100010
int pos[maxn]={0};

int main(){
    int n=0,error=0,flag=1,steps=0;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &pos[i]);
        if(pos[i]!=i)
            error++;
    }
    if(pos[0]!=0)
        error--;
    while(error>0){
        if(pos[0]==0){
            while(flag<n){
                if(pos[flag]!=flag){
                    swap(pos[0],pos[flag]);
                    steps++;
                    break;
                }
                flag++;
            }
        }
        while(pos[0]!=0){
            swap(pos[0],pos[pos[0]]);
            steps++;
            error--;
        }
    }
    printf("%d", steps);

    return 0;        
}