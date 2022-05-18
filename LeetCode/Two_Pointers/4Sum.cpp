/*
18
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        vector<vector<int>> res;
        if(nums.size()<4)   return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++){
            for(int j=nums.size()-1;j>=3;j--){
                int left=i+1;
                int right=j-1;
                while(left<right){
                    long long int sum=nums[i]*1ll+nums[left]*1ll+nums[right]*1ll+nums[j]*1ll;
                    if(sum==target){
                        ans.insert({nums[i],nums[left],nums[right],nums[j]});
                        left++;right--;
                    }
                    else if(sum<target)
                        left++;
                    else    right--;
                }
            }
        }
        for(auto it=ans.begin();it!=ans.end();it++)
            res.push_back(*it);
        return res;
    }
};