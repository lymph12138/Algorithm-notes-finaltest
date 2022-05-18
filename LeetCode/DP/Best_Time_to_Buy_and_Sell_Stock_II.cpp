/*
122
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2) return 0;
        int buy=-prices[0],sell=0;
        for(int i=1;i<n;i++){
            buy=max(buy,sell-prices[i]);
            sell=max(sell,buy+prices[i]);
        }
        return sell;
    }
};

int main(){
    int prices[3]={};
    cout<<Solution().maxProfit(prices);

    return 0;
}