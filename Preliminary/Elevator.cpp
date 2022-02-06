/*
an elevator costs 6 seconds to move up, and costs 4 seconds to move down, and stay for 5 seconds at each stop.
give one positive integer N, followed by N positive numbers, try to caculate the total time.
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int floor[n+1]={0};
    for(int i=1;i<n+1;i++)
        scanf("%d", &floor[i]);
    int time=0;
    for(int i=1;i<n+1;i++){
        if(floor[i]>floor[i-1])
            time+=(floor[i]-floor[i-1])*6+5;
        else
            time+=(floor[i-1]-floor[i])*4+5;
    }
    printf("%d", time);

    return 0;
}