/*
4
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(); int n=nums2.size();
        vector<double> dp;
        for(int i=0;i<m;i++)    dp.push_back(nums1[i]);
        for(int i=0;i<n;i++)    dp.push_back(nums2[i]);
        sort(dp.begin(),dp.end());
        if(dp.size()%2) return dp[dp.size()/2];
        else    return (dp[dp.size()/2-1]+dp[dp.size()/2])/2;
    }
};
