/*
75
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n0=0,n1=0,n2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)  n0++;
            else if(nums[i]==1) n1++;
            else n2++;
        }
        nums.clear();
        while(n0--) nums.push_back(0);
        while(n1--) nums.push_back(1);
        while(n2--) nums.push_back(2);
    }
};