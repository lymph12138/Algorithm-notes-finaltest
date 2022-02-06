/*
give an positive integer n less than 10^100, try to caculate every digits sum into spelling.
*/
#include <cstdio>
#include <cstring>
int main(){
    char c;
    int sum;
    char *digits[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    while((c=getchar())!='\n')
        sum=sum+c-'0';
    if(sum>=100)
        printf("%s %s %s", digits[sum/100], digits[sum/10%10], digits[sum%100]);
    else if(sum>=10)
        printf("%s %s", digits[sum/10], digits[sum%10]);
    else
        printf("%s", digits[sum]);

    return 0;
}