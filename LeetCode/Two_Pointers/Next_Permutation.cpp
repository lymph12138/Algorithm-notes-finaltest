/*
31
*/
class Solution {
public:
    int findmin(vector<int>& nums, int left, int right, int tag){
        int idx=left,minnum=nums[left];
        for(int i=left;i<=right;i++){
            if(nums[i]<minnum && nums[i]>tag){
                idx=i;
                minnum=nums[i];
            }
        }
        return idx;
    }
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int idx=n-2;
        while(idx>=0 && nums[idx]>=nums[idx+1])
            idx--;
        if(idx>=0){
            int x=findmin(nums,idx+1,n-1,nums[idx]);
            swap(nums[idx],nums[x]);
        }
        sort(nums.begin()+idx+1,nums.end());
    }
};