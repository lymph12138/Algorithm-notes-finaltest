/*
82
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)    return head;
        if(head->val!=head->next->val){
            head->next=deleteDuplicates(head->next);
            return head;
        }
        while(head->val==head->next->val){
            head=head->next;
            if(!head->next) return nullptr;   
        }
        return deleteDuplicates(head->next);
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* last=new ListNode(-110,head);
        ListNode* temp=last;
        while(head){
            if(head->next && head->val==head->next->val){
                while(head->next && head->val==head->next->val)
                    head=head->next;
                temp->next=head->next;
            }
            else    temp=temp->next;
            head=head->next;
        }
        return last->next;
    }
};