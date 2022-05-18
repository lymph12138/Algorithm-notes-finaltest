/*
309
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2) return 0;
        int buy=-prices[0],sell=0,cool=0;
        for(int i=1;i<n;i++){
            buy=max(buy,cool-prices[i]);
            cool=max(sell,cool);
            sell=buy+prices[i];
        }
        return max(sell,cool);
    }
};

int main(){
    vector<int> prices={1,2,3,1,4,9};
    cout<<Solution().maxProfit(prices);

    return 0;
}