/*
1673
*/
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> stack(k);
        int n=nums.size(),tag=0;
        for(int i=0;i<n;i++){
            while(tag && stack[tag-1]>nums[i] && n-i-k+tag-1>=0)
                tag--;
            if(tag<k)
                stack[tag++]=nums[i];
        }
        return stack;
    }
};