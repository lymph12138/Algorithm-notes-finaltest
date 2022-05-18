/*
55
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(ans>=i)
                ans=max(ans,nums[i]+i);
        }
        return ans>=nums.size()-1;
    }
};
*/