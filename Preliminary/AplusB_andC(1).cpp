/*
give three integers A, B, C from -2^63 to 2^63.
first line give n, means the number of tasks, following n lines.
try to caculate A+B>C or not
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        long long A, B, C, temp;
        scanf("%lld %lld %lld", &A, &B, &C);
        temp = A+B;
        if(A>0 && B>0 && temp<=0)
            printf("Case #%d: true\n", i+1);
        else if(A<0 && B<0 && temp>=0)
            printf("Case #%d: false\n", i+1);
        else if(temp>C)
            printf("Case #%d: true\n", i+1);
        else
            printf("Case #%d: false\n", i+1);
    }

    return 0;
}