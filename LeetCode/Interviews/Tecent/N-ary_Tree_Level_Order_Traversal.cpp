/*
429
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root)   return ans;
        vector<int> v;
        queue<Node*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            if(temp){
                v.push_back(temp->val);
                for(int j=0;j<temp->children.size();j++)
                    if(temp->children[j])
                        q.push(temp->children[j]);
            }
            else{
                ans.push_back(v);
                v.clear();
                if(q.empty())   break;
                q.push(nullptr);
            }
        }
        return ans;
    }
};