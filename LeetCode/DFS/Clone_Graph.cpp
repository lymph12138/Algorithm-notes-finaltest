/*
133
class Solution {
public:
    map<Node*,Node*> mp;
    Node* cloneGraph(Node* node) {
        if(!node)   return nullptr;
        if(mp.find(node)!=mp.end())
            return mp[node];
        mp[node]=new Node(node->val,node->neighbors);
        for(int i=0;i<(node->neighbors).size();i++)
            mp[node]->neighbors[i]=cloneGraph(node->neighbors[i]);
        return mp[node];
    }
};
*/