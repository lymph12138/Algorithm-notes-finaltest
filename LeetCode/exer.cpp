#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_map>
using namespace std;

int main(){
    priority_queue<int> pq;
    pq.push(1);pq.push(2);pq.push(3);
    int iter=pq.top();
    pq.pop();

    cout<<iter;

    return 0;
}