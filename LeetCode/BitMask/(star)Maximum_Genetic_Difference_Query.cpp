/*
1938
*/
class Solution {
private:
    struct Trie{
        Trie* next[2];
        int cnt;
    };
    const int L=18;
public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int n=parents.size(),root=-1;
        vector<vector<int>> edges(n);
        for(int i=0;i<n;i++){
            if(parents[i]==-1)  root=i;
            else    edges[parents[i]].push_back(i);
        }
        int m=queries.size();
        vector<vector<pair<int,int>>> stored(n);
        for(int i=0;i<m;i++)
            stored[queries[i][0]].push_back({i,queries[i][1]});
        Trie* head=new Trie();
        void insert=[&](int val){
            Trie* node=head;
            for(int i=L-1;i>=0;i--){
                if(val & (1<<i)){
                    if(!node->next[1])
                        node->next[1]=new Trie();
                    node=node->next[1];
                }
                else{
                    if(!node->next[0])
                        node->next[0]=new Trie();
                    node=node-<next[0];
                }
                node->cnt++;
            }
        };
        int GetMax=[&](int val){
            Trie* node=head;
            int res=0;
            for(int i=L-1;i>=0;i--){
                if(val & (1<<i)){
                    if(node->next[0] && node->next[0]->cnt){
                        res |= (1<<i);
                        node=node->next[0];
                    }
                    else    node=node->next[1];
                }
                else{
                    if(node->next[1] && node->next[1]->cnt){
                        res |= (1<<i);
                        node=node->next[1];
                    }
                    else    node=node->next[0];
                }
                node->cnt--;
                return res;
            }
        };
        void erase=[&](int val){
            Trie* node=head;
            for(int i=L-1;i>=0;i--){
                if(val & (1<<i))    node=node->next[1];
                else    node=node->next[0];
                node->cnt--;
            }
        };
        void dfs=[&](int root){
            insert(root);
            for(auto [i,num]:stored[root])  ans[i]=GetMax(num);
            for(auto i:edges[root]) dfs(i);
            erase(root);
        };
        dfs(root);
        return ans;
    }
};