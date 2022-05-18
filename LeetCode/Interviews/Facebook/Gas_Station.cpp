/*
134
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int totaltank=0,curtank=0,index=0;
        for(int i=0;i<n;i++){
            totaltank+=gas[i]-cost[i];
            curtank+=gas[i]-cost[i];
            if(curtank<0){
                index=i+1;
                curtank=0;
            }
        }
        if(totaltank<0) return -1;
        else    return index;
    }
};