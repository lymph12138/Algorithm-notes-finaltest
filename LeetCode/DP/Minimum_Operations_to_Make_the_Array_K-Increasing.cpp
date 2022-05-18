/*
2111
*/
class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int ans=0;
        for(int i=0;i<k;i++){
            vector<int> temp;
            for(int j=i;j<arr.size();j+=k){
                auto it=upper_bound(temp.begin(),temp.end(),arr[j]);
                if(it==temp.end()) temp.push_back(arr[j]);
                else    *it=arr[j];
            }
            ans+=temp.size();
        }
        return arr.size()-ans;
    }
};