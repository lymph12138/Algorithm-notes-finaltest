/*
1389
*/
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> array;
        for(int i=0;i<nums.size();i++){
            array.insert(array.begin()+index[i],nums[i]);
        }
        return array;
    }
};