/*
16
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans,sum;
        int diff=INT_MAX;
        for(int left=0;left<nums.size()-2;left++){
            int mid=left+1;
            int right=nums.size()-1;
            while(mid<right){
                sum=nums[left]+nums[mid]+nums[right];
                if(target==sum) return target;
                if(diff>abs(target-sum)){
                    ans=sum;
                    diff=abs(target-sum);
                }
                if(sum<target)  mid++;
                else right--;
            }
        }
        return ans;
    }
};