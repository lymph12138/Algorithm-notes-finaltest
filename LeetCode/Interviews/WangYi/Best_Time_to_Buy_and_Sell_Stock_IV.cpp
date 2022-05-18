/*
188
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k==0)    return 0;
        int n=prices.size();
        vector<int> buy(k,INT_MIN),sell(k,0);
        for(int i=0;i<prices.size();i++){
            buy[0]=max(buy[0],-prices[i]);
            sell[0]=max(sell[0],buy[0]+prices[i]);
            for(int j=1;j<k;j++){
                buy[j]=max(buy[j],sell[j-1]-prices[i]);
                sell[j]=max(sell[j],buy[j]+prices[i]);
            }
        }
        return sell[k-1];
    }
};