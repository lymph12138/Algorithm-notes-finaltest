/*

*/
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

#define maxn 10010
int dp[maxn],num[maxn],s[maxn]={0};
int main(){
    int K;
    cin>>K;
    bool tag=false;
    for(int i=0;i<K;i++){
        scanf("%d", &num[i]);
        if(num[i]>=0)   tag=true;
    }
    if(tag==false){
        printf("0 %d %d", num[0], num[K-1]);
        return 0;
    }
    dp[0]=num[0];
    for(int i=1;i<K;i++){
        if(dp[i-1]+num[i]>num[i]){
            dp[i]=dp[i-1]+num[i];
            s[i]=s[i-1];
        }
        else{
            dp[i]=num[i];
            s[i]=i;
        }
    }
    int k=0;
    for(int i=0;i<K;i++)
        if(dp[i]>dp[k])
            k=i;
    printf("%d %d %d",dp[k],num[s[k]],num[k]);

    return 0;
}