/*
give any positive integer N, try to caculate the total number of 1's.
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    int n,a=1,left,right,now,ans=0;
    scanf("%d", &n);
    while(n/a){
        left=(n/10)/a;
        right=(n%a);
        now=(n/a)%10;
        if(now==0)  ans+=left*a;
        else if(now==1) ans+=left*a+right+1;
        else ans+=(left+1)*a;
        a*=10;
    }
    printf("%d", ans);

    return 0;
}