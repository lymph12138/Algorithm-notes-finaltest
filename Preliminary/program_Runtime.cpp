/*
give two number c1 and c2, CLK_TCK=100; try to caculate the time between c2 and c1;
specification hh:mm:ss, time = (c2-c1)/CLK_TCK s, require to rounding.
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
int main(){
    int c1, c2;
    int ans;
    int flag=0;
    scanf("%d %d", &c1, &c2);
    ans = (c2-c1)/100;
    if((c2-c1)%100>=50)
        flag = 1;
    printf("%02d:%02d:%02d",ans/3600, ans%3600/60, ans%60+flag);

    return 0;
}