/*
116,117
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)   return nullptr;
        queue<Node*>q;
        q.push(root);
        Node* temp=nullptr;
        while(q.size()){
            int size=q.size();
            for(int i=0;i<size;i++){
                Node* a=q.front();
                q.pop();
                if(!temp)   temp=a;
                else{
                    temp->next=a;
                    temp=a;
                }
                if(a->left) q.push(a->left);
                if(a->right)    q.push(a->right);
                if(i==size-1){
                    a->next=nullptr;
                    temp=nullptr;
                }
            }
        }
        return root;
    }
};
*/