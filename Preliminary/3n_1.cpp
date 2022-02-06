/*
time limit 400ms, memory limit 65536kb
input number n, if it is an odd, n=(3*n+1)/2;if it is even, n=n/2. Try to caculate the number of steps n become 1;
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
int main(){
    int n=0;
    int steps=0;
    scanf("%d", &n);
    while(n!=1){
        if(n%2==0)
            n=n/2;
        else
            n=(3*n+1)/2;
        steps=steps+1;
    }
    printf("%d", steps);
    return 0;
}