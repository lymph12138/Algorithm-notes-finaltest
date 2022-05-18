/*
503
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1),dp;
        for(int i=0;i<n*2;i++){
            while(dp.size() && nums[dp.back()]<nums[i%n]){
                ans[dp.back()]=nums[i%n];
                dp.pop_back();
            }
            dp.push_back(i%n);
        }
        return ans;
    }
};