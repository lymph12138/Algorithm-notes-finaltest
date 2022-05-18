/*
646
*/
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](vector<int> a,vector<int> b){
            if(a[1]==b[1])  return a[0]<b[0];
            else    return a[1]<b[1];
        });
        int right=pairs[0][1];
        int ans=1;
        for(int i=1;i<pairs.size();i++){
            if(pairs[i][0]<=right)   continue;
            ans++;
            right=pairs[i][1];
        }
        return ans;
    }
};