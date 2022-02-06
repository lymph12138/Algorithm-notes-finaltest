/*
give an integer N, try to find the maximum consecutive factors
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    long long start=0,length=0;
    long long N;
    scanf("%lld",&N);
    for(long long i=2;i<=(long long)sqrt(N);i++){
        long long temp=1, j=i;
        while(1){
            temp*=j;
            if(N%temp!=0)   break;
            if(j-i+1>length){
                start=i;
                length=j-i+1;
            }
            j++;
        }
    }
    if(length==0)   printf("1\n%lld", N);
    else{
        printf("%lld\n", length);
        for(long long i=start;i<start+length;i++){
            if(i==start)    printf("%lld", i);
            else    printf("*%lld",i);
        }
    }

    return 0;
}