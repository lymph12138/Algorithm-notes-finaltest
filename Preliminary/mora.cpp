/*
two man a and b are moraing, give four number a1, a2, b1 ,b2, and mora counting n.
try to caculate the win times of a and b.if a1+b1=a2, a1+b1!=b2, a win
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
int main(){
    int n, counta=0, countb=0;
    scanf("%d", &n);
    while(n--){
        int a1, a2, b1, b2;
        scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
        if(a1+b1==a2 && a1+b1!=b2)
            counta++;
        if(a1+b1!=a2 && a1+b1==b2)
            countb++;
    }
    printf("%d %d", countb, counta);

    return 0;
}