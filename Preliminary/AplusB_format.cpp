/*
give to integers A and B, try to caculate A+B in standard format.
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    int A, B, C;
    scanf("%d %d", &A, &B);
    C=A+B;
    if(C<0){
        C=-C;
        printf("-");
    }
    if(C<1000)
        printf("%d", C);
    else if(C<1000000)
        printf("%d,%03d", C/1000, C%1000);
    else 
        printf("%d,%03d,%03d", C/1000000, (C/1000)%1000, C%1000);
    
    return 0;
}