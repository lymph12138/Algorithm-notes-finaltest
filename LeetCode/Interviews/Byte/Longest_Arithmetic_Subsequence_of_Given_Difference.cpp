/*
1218
*/

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size(),ans=0;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]+difference]=mp[arr[i]]+1;
            ans=max(ans,mp[arr[i]+difference]);
        }
        return ans;
    }
};