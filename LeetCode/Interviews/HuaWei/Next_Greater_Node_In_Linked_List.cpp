/*
1019
*/

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> num;
        while(head){
            num.push_back(head->val);
            head=head->next;
        }
        for(int i=0;i<num.size();i++){
            auto it=upper_bound(num.begin()+i,num.end(),num[i]);
            if(it!=num.end())   num[i]=*it;
            else    num[i]=0;
        }
        return num;
    }
};