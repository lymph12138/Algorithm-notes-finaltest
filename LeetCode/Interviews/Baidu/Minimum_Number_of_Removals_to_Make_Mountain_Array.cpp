/*
1671
*/
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int> dpup(n,1),dpdown(n,1);
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i])
                    dpup[i]=max(dpup[i],1+dpup[prev]);
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int prev=n-1;prev>i;prev--){
                if(nums[prev]<nums[i])
                    dpdown[i]=max(dpdown[i],1+dpdown[prev]);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dpup[i]==1 || dpdown[i]==1)
                continue;
            ans=max(ans,dpup[i]+dpdown[i]-1);
        }
            
        return n-ans;
    }
};