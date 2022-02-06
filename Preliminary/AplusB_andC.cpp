/*
time limit 50ms, memory limit 65536kb
give three number A, B, C from -2^31 to 2^31, configure A+B if bigger than C or not
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
int main(){
    int n;
    int cases=1;
    scanf("%d", &n);
    while(n--){
        long long A, B, C;
        scanf("%lld %lld %lld", &A, &B, &C);
        if(A+B>C)
            printf("Case #%d: true\n", cases++);
        else
            printf("Case #%d: false\n", cases++);
    }
    return 0;
}