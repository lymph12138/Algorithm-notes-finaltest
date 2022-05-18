/*
1707
*/
class BinaryTrie{
public:
    const int L=32;
    int MinNum=INT_MAX;
    BinaryTrie* next[2];
    void insert(int val){
        BinaryTrie* node=this;
        node->MinNum=min(val,node->MinNum);
        for(int i=L-1;i>=0;i--){
            int bit=(val>>i) & 1;
            if(!node->next[bit])
                node->next[bit]=new BinaryTrie();
            node=node->next[bit];
            node->MinNum=min(node->MinNum,val);
        }
    }
    int GetMaxWithLimit(int val, int limit){
        BinaryTrie* node=this;
        if(node->MinNum>limit)  return -1;
        int ans=0;
        for(int i=L-1;i>=0;i--){
            int bit=(val>>i) & 1;
            if(node->next[bit^1] && node->next[bit^1]->MinNum<=limit){
                ans |= 1<<i;
                bit ^=1;
            }
            node=node->next[bit];
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        BinaryTrie* root=new BinaryTrie();
        for(auto num:nums)  root->insert(num);
        vector<int> ans;
        for(int i=0;i<queries.size();i++)
            ans.push_back(root->GetMaxWithLimit(queries[i][0],queries[i][1]));
        return ans;
    }
};