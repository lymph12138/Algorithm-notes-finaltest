/*
2141
*/
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(),batteries.end());
        long long sum=accumulate(batteries.begin(),batteries.end(),0L);
        int size=batteries.size(),waste=0;
        while(batteries[size-1-waste]>sum/(n-waste))
            sum-=batteries[size-1-waste++];
        return sum/(n-waste);
    }
};