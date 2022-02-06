/*
give two integers MSize and TSize, and followed TSize integers,
try to caculate the position of TSize integers when hashing.
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define maxn 11111
bool HashTable[maxn]={0};

int Isprime(int n){
    if(n<=1)    return 0;
    for(int i=2;i<=sqrt(n);i++)
        if(n%i==0)
            return 0;
    return 1;
}

int main(){
    int MSize, TSize, a;
    scanf("%d%d", &MSize, &TSize);
    while(!Isprime(MSize)){
        MSize++;
    }
    for(int i=0;i<TSize;i++){
        int pos;
        scanf("%d", &a);
        pos=a%MSize;
        if(HashTable[pos]==false){
            HashTable[pos]=true;
            if(i==0)    printf("%d", pos);
            else    printf(" %d", pos);
        }
        else{
            int step;
            for(step=1;step<MSize;step++){
                pos=(a+step*step)%MSize;
                if(HashTable[pos]==false){
                    HashTable[pos]=true;
                    if(i==0)    printf("%d", pos);
                    else    printf(" %d", pos);
                    break;
                }
            }
            if(step>=MSize){
                if(i>0) printf(" ");
                printf("-");
            }        
        }
    }

    return 0;
}