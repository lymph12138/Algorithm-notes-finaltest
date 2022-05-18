/*
152
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==1)    return nums[0];
        int curmax=1,curmin=1,ans=-11;
        for(int i=0;i<n;i++){
            int temp=curmin;
            curmin=min(min(temp*nums[i],curmax*nums[i]),nums[i]);
            curmax=max(max(temp*nums[i],curmax*nums[i]),nums[i]);
            ans=max(ans,curmax);
        }
        return ans;
    }
};