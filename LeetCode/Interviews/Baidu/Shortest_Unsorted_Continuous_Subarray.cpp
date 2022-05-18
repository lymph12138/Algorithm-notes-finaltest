/*
581
*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());
        if(n==1)    return 0;
        vector<int> ans;
        for(int i=0;i<n;i++)
            if(nums[i]!=temp[i])
                ans.push_back(i);
        if(ans.size()==0)   return 0;
        return ans.back()-ans[0]+1;
    }
};
