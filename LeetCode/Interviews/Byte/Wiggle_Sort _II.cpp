/*
324
*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp=nums;
        nums.clear();
        int n=temp.size();
        int k=(n%2)?(n/2+1):n/2;
        for(int i=0;i<k;i++){
            nums.push_back(temp[k-i-1]);
            if(n-i-1>=k)   nums.push_back(temp[n-i-1]);
        }
    }
};