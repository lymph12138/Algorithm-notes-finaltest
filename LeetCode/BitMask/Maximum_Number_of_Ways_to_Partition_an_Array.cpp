/*
2025
*/
class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n=nums.size();
        long sum=0,left=0,right;
        for(auto num:nums)  sum+=num;
        unordered_map<long,int> l,r;
        for(int i=0;i<n-1;i++){
            left+=nums[i];
            right=sum-left;
            r[right-left]++;
        }
        int ans=r[0];left=0;
        for(auto num:nums){
            left+=num;
            right=sum-left;
            ans=max(ans,r[k-num]+l[num-k]);
            r[right-left]--;
            l[right-left]++;
        }
        return ans;
    }
};