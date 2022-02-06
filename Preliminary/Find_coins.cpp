/*
give two positive integers n and m, and following n face of values of coins
m means the amount of money eva has to pay. try to caculate is there has two coins to offer or not.
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int coins[1005]={0};
int main(){
    int n,m,temp;
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%d", &temp);
        coins[temp]++;
    }
    for(int i=0;i<1005;i++){
        if(coins[i] && coins[m-i]){
            if(i==m-i && coins[i]<=1)
                continue;
            printf("%d %d\n", i, m-i);
            return 0;
        }
    }
    printf("No Solution\n");

    return 0;

}