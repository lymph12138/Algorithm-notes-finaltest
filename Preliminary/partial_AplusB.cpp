/*
give four number A , Da, B, Db. A and B from 0 to 10^10, Da and Db from 0 to 9.
try to caculate Pa+Pb, Pa means "A's Da partial", Pb means"B's Db partial"
12342, 2, 23453, 3 Pa=22, Pb=33
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
int main(){
    long long A, B;
    int Da, Db;
    long long Pa=0,Pb=0;
    scanf("%lld %d %lld %d", &A, &Da, &B, &Db);
    while(A!=0){
        if(A%10==Da)
            Pa=Pa*10+Da;
        A=A/10;
    }
    while(B!=0){
        if(B%10==Db)
            Pb=Pb*10+Db;
        B=B/10;
    }
    printf("%lld", Pa+Pb);

    return 0;
}