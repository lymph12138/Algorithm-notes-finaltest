/*
1713
*/
class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<target.size();i++)
            mp[target[i]]=i;
        vector<int> stack;
        for(auto a:arr){
            if(mp.find(a)==mp.end())    continue;
            if(stack.empty() || mp[a]>stack.back()){
                stack.push_back(mp[a]);
                continue;
            }
            auto pos=lower_bound(stack.begin(),stack.end(),mp[a]);
            *pos=mp[a];
        }
        return target.size()-stack.size();
    }
};