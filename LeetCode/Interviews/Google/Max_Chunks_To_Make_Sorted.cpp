/*
769
*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int m=arr.size();
        int maxnum=0,count=0;
        for(int i=0;i<m;i++){
            maxnum=max(maxnum,arr[i]);
            if(maxnum==i)   count++;
        }
        return count;
    }
};