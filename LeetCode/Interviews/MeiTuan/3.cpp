/*
384
*/

class Solution {
public:
    vector<int> arr;
    Solution(vector<int>& nums) {
        swap(arr,nums);
    }
    
    vector<int> reset() {
        return arr;
    }
    
    vector<int> shuffle() {
        vector<int> temp=arr;
        for(int i=0;i<temp.size();i++)
            swap(temp[i],temp[rand()%temp.size()]);
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */