/*
1695
*/
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> st;
        int maxsum=0,cursum=0,l=0,r=0,n=nums.size();
        for(;r<n;r++){
            while(st.count(nums[r])){
                cursum-=nums[l];
                st.erase(nums[l++]);
            }
            st.insert(nums[r]);
            cursum+=nums[r];
            maxsum=max(maxsum,cursum);
        }
        return maxsum;
    }
};