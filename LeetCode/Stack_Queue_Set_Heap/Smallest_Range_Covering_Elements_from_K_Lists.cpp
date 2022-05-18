/*
632
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
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int left,right;
        int n=nums.size();
        set<array<int,3>> minheap;
        for(int i=0;i<n;i++)    minheap.insert({nums[i][0],i,0});
        left=minheap.begin()->front(),right=minheap.rbegin()->front();
        while(minheap.begin()->back()!=nums[(*minheap.begin())[1]].size()-1){
            auto [num,i,j]=*minheap.begin();
            minheap.erase(minheap.begin());
            minheap.insert({nums[i][j+1],i,j+1});
            if(right-left>minheap.rbegin()->front()-minheap.begin()->front()){
                left=minheap.begin()->front(),right=minheap.rbegin()->front();
            }
        }
        //cout<<left<<" "<<right;
        return {left,right};
    }
};


int main(){
    vector<vector<int>> nums={{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    //{{1,2,3},{1,2,3},{1,2,3}},{{4,10,15,24,26},{0,9,12,20},{5,18,22,30}}
    //auto [left,right]=Solution().smallestRange(nums);
    Solution().smallestRange(nums);
    //cout<<left<<" "<<right;

    return 0;
}