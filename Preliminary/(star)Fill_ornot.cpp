/*
give four positive numbers:Cmax,D,Dvag,N, and following N lines Pi and Di
*/
#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#define inf 100000
using namespace std;

struct place{
    float price;
    float distance;
};
bool cmp(place p1, place p2){
    return p1.distance<p2.distance;
}

int main(){
    float Cmax, D, Davg;
    int N;
    scanf("%f %f %f %d", &Cmax, &D, &Davg, &N);
    vector <place> pl(N+1);
    for(int i=0;i<N;i++)
        scanf("%f %f", &pl[i].price, &pl[i].distance);
    pl[N].price=0;
    pl[N].distance=D;
    sort(pl.begin(), pl.end(),cmp);
    float nowprice=0;
    float nowdist=0;
    float maxdist=0;
    float totalprice=0;
    float leftdist=0;
    if(pl[0].distance!=0){
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    else nowprice=pl[0].price;
    while(nowdist<D){
        maxdist=nowdist+Cmax*Davg;
        float minprice=inf;
        float minpricedist=0;
        int flag=0;
        for(int i=1;i<=N&&pl[i].distance<=maxdist;i++){
            if(pl[i].distance<=nowdist)
                continue;
            if(pl[i].price<=nowprice){
                totalprice+=(pl[i].distance-nowdist-leftdist)*nowprice/Davg;
                leftdist=0;
                nowprice=pl[i].price;
                nowdist=pl[i].distance;
                flag=1;
                break;
            }
            if(pl[i].price<minprice){
                minprice=pl[i].price;
                minpricedist=pl[i].distance;
            }
        }
        if(flag==0 && minprice!=inf){
            totalprice+=(Cmax-leftdist/Davg)*nowprice;
            leftdist=Cmax*Davg-(minpricedist-nowdist);
            nowprice=minprice;
            nowdist=minpricedist;
        }
        if(flag==0 && minprice==inf){
            nowdist+=Cmax*Davg;
            printf("The maximum travel distance = %.2f", nowdist);
            return 0;
        }
    }
    printf("%.2f", totalprice);
    
    return 0;
}