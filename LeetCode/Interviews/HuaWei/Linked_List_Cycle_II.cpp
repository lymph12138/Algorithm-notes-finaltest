/*
142
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> st;
        while(head){
            if(st.find(head)!=st.end()) return head;
            st.insert(head);
            head=head->next;
        }
        return nullptr;
    }
};

