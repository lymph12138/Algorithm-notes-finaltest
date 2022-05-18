/*
996
class Solution {
public:
    int count=0;
    bool IsSquare(int n){
        int x=sqrt(n);
        return n==x*x;
    }
    void Solve(vector<int>& nums,int idx){
        if(idx==nums.size()){
            count++;
            return;
        }
        set<int> vis;
        for(int i=idx;i<nums.size();i++){
            if((idx==0 || IsSquare(nums[idx-1]+nums[i])) && !vis.count(nums[i])){
                swap(nums[idx],nums[i]);
                Solve(nums,idx+1);
                swap(nums[idx],nums[i]);
                vis.insert(nums[i]);
            }
        }
    }
    int numSquarefulPerms(vector<int>& nums) {
        Solve(nums,0);
        return count;
    }
};
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
vector <int> num;
bool IsSquare(int n){
    int x=sqrt(n);
    return x*x==n;
}
int count=0;
void Solve(vector<int> &num,int idx){
    if(idx==num.size()){
        count++;
        return;
    }
    set<int> vis;
    for(int i=idx;i<num.size();i++){
        if((idx==0 || IsSquare(num[idx-1]+num[i])) && !vis.count(num[i])){
            swap(num[idx],num[i]);
            Solve(num,idx+1);
            swap(num[idx],num[i]);
            vis.insert(num[i]);
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)    scanf("%d", &num[i]);
    Solve(num,0);
    printf("%d", count);

    return 0;
}
