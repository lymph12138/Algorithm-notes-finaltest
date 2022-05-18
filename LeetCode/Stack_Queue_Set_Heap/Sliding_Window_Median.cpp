/*
480
*/
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        set<pair<double,int>> maxheap;
        set<pair<double,int>,greater<>> minheap;
        vector<double> ans;
        int left=0,right=1;
        maxheap.insert({nums[0],0});
        while(right<k){
            maxheap.insert({nums[right],right});
            right++;  
        }
        while(maxheap.size()>minheap.size()+1){
            minheap.insert(*maxheap.begin());
            maxheap.erase(maxheap.begin());
        }
        if(maxheap.size()==minheap.size())
            ans.push_back((maxheap.begin()->first+minheap.begin()->first)/2.0);
        else    ans.push_back(maxheap.begin()->first);
        while(right<n){
            if(minheap.size()==0){
                ans.push_back(nums[right]);
                right++;
                continue;
            }
            maxheap.insert({nums[right],right});
            if(maxheap.begin()->first<minheap.begin()->first){
                maxheap.insert(*minheap.begin());
                minheap.insert(*maxheap.begin());
                minheap.erase(minheap.begin());
                maxheap.erase(maxheap.begin());
            }
            auto iter=minheap.find({nums[left],left});
            if(iter!=minheap.end()){
                minheap.erase(iter);
                if(minheap.size()<maxheap.size()){
                    minheap.insert(*maxheap.begin());
                    maxheap.erase(maxheap.begin());
                }
            }
            else{
                auto iter=maxheap.find({nums[left],left});
                maxheap.erase(iter);
            }
            if(maxheap.size()==minheap.size())
                ans.push_back((maxheap.begin()->first+minheap.begin()->first)/2.0);
            else    ans.push_back(maxheap.begin()->first);

            left++,right++;
        }
        return ans;
    }
};

int main(){
    vector<int> nums={1,3,-1,-3,5,3,6,7};
    int k=3;
    Solution().medianSlidingWindow(nums,k);

    return 0;
}