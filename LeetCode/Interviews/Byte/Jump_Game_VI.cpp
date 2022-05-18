/*
1696
*/


class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size(),ans=nums[0];
        priority_queue<pair<int,int>> pq;
        pq.push({nums[0],0});
        for(int i=1;i<n;i++){
            while(!pq.empty()){
                if(i-pq.top().second<=k){
                    ans=nums[i]+pq.top().first;
                    pq.push({ans,i});
                    break;
                }
                else    pq.pop();
            }
        }
        return ans;
    }
};