/*
2034
*/
class StockPrice {
public:
    int time;
    unordered_map<int,int> mp;
    set<pair<int,int>> prices;
    StockPrice() {
        time=0;
    }
    
    void update(int timestamp, int price) {
        if(time<timestamp)  time=timestamp;
        else{
            int p=mp[timestamp];
            prices.erase({p,timestamp});
        }
        mp[timestamp]=price;
        prices.insert({price,timestamp});
    }
    
    int current() {
        return mp[time];
    }
    
    int maximum() {
        return (*prices.rbegin()).first;
    }
    
    int minimum() {
        return (*prices.begin()).first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */