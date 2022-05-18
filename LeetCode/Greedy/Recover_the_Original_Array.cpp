/*
2122
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;



class Solution {
public:
    vector<int> ans;
    bool solve(vector<int> nums, int k){
        ans.clear();
        int n=nums.size()/2;
        for(int i=0;i<2*n;i++){
            if(nums[i]==-1) continue;
            auto it=lower_bound(nums.begin()+i,nums.end(),nums[i]+2*k);
            if(it==nums.end())  return false;
            if(*it==nums[i]+2*k){
                *it=-1;
                ans.push_back(nums[i]+k);
            }
        }
        return ans.size()==n;
    }
    vector<int> recoverArray(vector<int>& nums) {
        int n=nums.size()/2;
        sort(nums.begin(),nums.end());
        int begin=nums[0];
        for(int i=1;i<2*n;i++){
            if((nums[i]-begin)%2 || nums[i]==nums[i-1]) continue;
            if(solve(nums,(nums[i]-begin)/2))   break;
        }
        return ans;
    }
};

int main(){
    vector<int> nums={5,435};
    Solution().recoverArray(nums);

    return 0;
}