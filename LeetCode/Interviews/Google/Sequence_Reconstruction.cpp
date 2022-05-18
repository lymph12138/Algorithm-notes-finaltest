/*
444
*/
class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n=nums.size(),index=1;
        if(n==1){
            if(sequences.size()==1 && sequences[0].size()==1 && nums[0]==sequences[0][0])
                return true;
            return false;
        }
        vector<int> rank(n+1,0);
        for(auto num:nums)  rank[num]=index++;
        vector<bool> edge(n-1,false);
        for(int i=0;i<sequences.size();i++){
            if(sequences[i].size()==1)  continue;
            for(int j=1;j<sequences[i].size();j++){
                if(rank[sequences[i][j-1]]>=rank[sequences[i][j]])
                    return false;
                if(rank[sequences[i][j-1]]+1==rank[sequences[i][j]])
                    edge[rank[sequences[i][j-1]]-1]=true;
            }
        }
        for(auto e:edge)
            if(!e)  return false;
        return true;
    }
};